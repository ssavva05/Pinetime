#include "AlertNotificationService.h"
#include <hal/nrf_rtc.h>
#include <cstring>
#include <algorithm>
#include "NotificationManager.h"
#include "systemtask/SystemTask.h"

using namespace Pinetime::Controllers;

constexpr ble_uuid16_t AlertNotificationService::ansUuid;
constexpr ble_uuid16_t AlertNotificationService::ansCharUuid;
constexpr ble_uuid16_t AlertNotificationService::ansEventUuid;


int AlertNotificationCallback(uint16_t conn_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt *ctxt, void *arg) {
  auto anService = static_cast<AlertNotificationService*>(arg);
  return anService->OnAlert(conn_handle, attr_handle, ctxt);
}

void AlertNotificationService::Init() {
  int res;
  res = ble_gatts_count_cfg(serviceDefinition);
  ASSERT(res == 0);

  res = ble_gatts_add_svcs(serviceDefinition);
  ASSERT(res == 0);
}

AlertNotificationService::AlertNotificationService ( System::SystemTask& systemTask, NotificationManager& notificationManager )
  : characteristicDefinition{
                {
                        .uuid = (ble_uuid_t *) &ansCharUuid,
                        .access_cb = AlertNotificationCallback,
                        .arg = this,
                        .flags = BLE_GATT_CHR_F_WRITE
                },
                {
                        .uuid = (ble_uuid_t *) &ansEventUuid,
                        .access_cb = AlertNotificationCallback,
                        .arg = this,
                        .flags = BLE_GATT_CHR_F_NOTIFY,
                        .val_handle = &eventHandle
                },
                {
                  0
                }
        },
    serviceDefinition{
                {
                        /* Device Information Service */
                        .type = BLE_GATT_SVC_TYPE_PRIMARY,
                        .uuid = (ble_uuid_t *) &ansUuid,
                        .characteristics = characteristicDefinition
                },
                {
                        0
                },
        }, systemTask{systemTask}, notificationManager{notificationManager} {
}

int AlertNotificationService::OnAlert(uint16_t conn_handle, uint16_t attr_handle,
                                                    struct ble_gatt_access_ctxt *ctxt) {
  if (ctxt->op == BLE_GATT_ACCESS_OP_WRITE_CHR) {

    NotificationManager::Notification notif;
    constexpr size_t headerSize = 9;

    uint8_t* notification = new uint8_t[headerSize];
    /*
        notification[0] = 0x01
        notification[1] = (byte) notification Id
        notification[2] = 0x02
        notification[3] = (byte) notification_length
        notification[4] = (byte) notification_length
        notification[5] = (byte) category
        notification[6] = 0x03;
        notification[7] = (byte) subject_length
        notification[8] = (byte) body_length
        subject = (subject_length)
        body = (body_length)
        datetime
        notification[notification_length - 1] = 0x0f
    
    */

    // debug = b AlertNotificationService.cpp:87
    // set $i = 0
    // p ctxt->om.om_data[$i++]

    os_mbuf_copydata(ctxt->om, 0, headerSize, notification);

    uint8_t subject_length = notification[7];
    uint8_t body_length = notification[8];    
    uint8_t category = notification[5];

    notif.alertID = notification[1];    

    // Subject
    os_mbuf_copydata(ctxt->om, headerSize, subject_length + 1, notif.subject.data());
    notif.subject[subject_length] = '\0';

    // Body
    os_mbuf_copydata(ctxt->om, headerSize + subject_length, body_length + 1, notif.message.data());
    notif.message[body_length] = '\0';

    // Date Time
    os_mbuf_copydata(ctxt->om, headerSize + subject_length + body_length, 5, notif.year.data());
    notif.year[4] = '\0';
    os_mbuf_copydata(ctxt->om, headerSize + subject_length + body_length + 4, 3, notif.month.data());
    notif.month[2] = '\0';
    os_mbuf_copydata(ctxt->om, headerSize + subject_length + body_length + 6, 3, notif.day.data());
    notif.day[2] = '\0';
    os_mbuf_copydata(ctxt->om, headerSize + subject_length + body_length + 9, 3, notif.hour.data());
    notif.hour[2] = '\0';
    os_mbuf_copydata(ctxt->om, headerSize + subject_length + body_length + 11, 3, notif.minute.data());
    notif.minute[2] = '\0';
    os_mbuf_copydata(ctxt->om, headerSize + subject_length + body_length + 13, 3, notif.second.data());
    notif.second[2] = '\0';

    /*constexpr size_t stringTerminatorSize = 1; // end of string '\0'
    constexpr size_t headerSize = 3;
    const auto maxMessageSize {NotificationManager::MaximumMessageSize()};
    const auto maxBufferSize{maxMessageSize + headerSize};

    const auto dbgPacketLen = OS_MBUF_PKTLEN(ctxt->om);
    size_t bufferSize = std::min(dbgPacketLen + stringTerminatorSize, maxBufferSize);
    auto messageSize = std::min(maxMessageSize, (bufferSize-headerSize));

    NotificationManager::Notification notif;
    os_mbuf_copydata(ctxt->om, headerSize, messageSize-1, notif.message.data());
    notif.message[messageSize-1] = '\0';

   
    uint8_t* category = new uint8_t[1];

    os_mbuf_copydata(ctxt->om, 0, 1, category);*/

    notif.category = Pinetime::Controllers::NotificationManager::Categories::Unknown;
    Pinetime::System::SystemTask::Messages event = Pinetime::System::SystemTask::Messages::OnNewNotification;

    switch(category) {
      
      case NOTIFICATION_EMAIL:
        notif.category = Pinetime::Controllers::NotificationManager::Categories::Email;
        break;
      /*case NOTIFICATION_CALL_OFF:
        notif.category = Pinetime::Controllers::NotificationManager::Categories::IncomingCall;
        //event = Pinetime::System::SystemTask::Messages::OnNewCall;
        break;*/
      case NOTIFICATION_CALL_OFF:
      case NOTIFICATION_MISSED_CALL:
        notif.category = Pinetime::Controllers::NotificationManager::Categories::MissedCall;
        break;
      case NOTIFICATION_SMS:
        notif.category = Pinetime::Controllers::NotificationManager::Categories::Sms;
        break;
      case NOTIFICATION_CALENDAR:
        notif.category = Pinetime::Controllers::NotificationManager::Categories::Schedule;
        break;
      case NOTIFICATION_WECHAT:
      case NOTIFICATION_VIBER:
      case NOTIFICATION_SNAPCHAT:
      case NOTIFICATION_WHATSAPP:
      case NOTIFICATION_FACEBOOK:
      case NOTIFICATION_MESSENGER:
      case NOTIFICATION_INSTAGRAM:
      case NOTIFICATION_TWITTER:
      case NOTIFICATION_LINKEDIN:
      case NOTIFICATION_LINE:
      case NOTIFICATION_SKYPE:
        notif.category = Pinetime::Controllers::NotificationManager::Categories::InstantMessage;
        break;
      default:
        notif.category = Pinetime::Controllers::NotificationManager::Categories::Unknown;
        break;
    }
    
    // debug = b AlertNotificationService.cpp:165
    notificationManager.Push(std::move(notif));
    systemTask.PushMessage(event);
  }
  return 0;
}

void AlertNotificationService::event(char event) {
  auto *om = ble_hs_mbuf_from_flat(&event, 1);

  uint16_t connectionHandle = systemTask.nimble().connHandle();

  if (connectionHandle == 0 || connectionHandle == BLE_HS_CONN_HANDLE_NONE) {
    return;
  }

  ble_gattc_notify_custom(connectionHandle, eventHandle, om);
}