#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_NOT_UNKNOWN
#define LV_ATTRIBUTE_IMG_NOT_UNKNOWN
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_NOT_UNKNOWN uint8_t not_unknown_map[] = {
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 0*/
  0x1b, 0x13, 0x0a, 0xff, 	/*Color of index 1*/
  0x45, 0x2a, 0x02, 0xff, 	/*Color of index 2*/
  0x39, 0x28, 0x12, 0xff, 	/*Color of index 3*/
  0x7a, 0x4b, 0x10, 0xff, 	/*Color of index 4*/
  0x65, 0x4a, 0x26, 0xff, 	/*Color of index 5*/
  0xb0, 0x6c, 0x1a, 0xff, 	/*Color of index 6*/
  0x8b, 0x66, 0x38, 0xff, 	/*Color of index 7*/
  0xb8, 0x88, 0x49, 0xff, 	/*Color of index 8*/
  0xf3, 0x97, 0x10, 0xff, 	/*Color of index 9*/
  0xf1, 0xa0, 0x36, 0xff, 	/*Color of index 10*/
  0xf6, 0xb4, 0x68, 0xff, 	/*Color of index 11*/
  0xf7, 0xca, 0x92, 0xff, 	/*Color of index 12*/
  0xf6, 0xde, 0xbd, 0xff, 	/*Color of index 13*/
  0xfa, 0xef, 0xdf, 0xff, 	/*Color of index 14*/
  0xf8, 0xfb, 0xf9, 0xff, 	/*Color of index 15*/

  0x00, 0x36, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x04, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x40, 0x00, 0x00, 0x00, 0x00, 
  0x39, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x92, 0x00, 0x00, 0x00, 0x00, 
  0x69, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x96, 0x00, 0x00, 0x00, 0x00, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x00, 0x00, 0x00, 0x00, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x10, 0x00, 0x00, 0x00, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x10, 0x00, 0x00, 0x00, 
  0x99, 0x99, 0x99, 0x99, 0x9a, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xa9, 0x99, 0x99, 0x99, 0x99, 0x10, 0x00, 0x00, 0x00, 
  0x99, 0x99, 0x99, 0x99, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xa9, 0x99, 0x99, 0x99, 0x10, 0x00, 0x00, 0x00, 
  0x99, 0x99, 0x99, 0x9a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa9, 0x99, 0x99, 0x99, 0x10, 0x00, 0x00, 0x00, 
  0x99, 0x99, 0x99, 0x99, 0xbc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcb, 0x99, 0x99, 0x99, 0x99, 0x10, 0x15, 0x53, 0x00, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x10, 0x3b, 0xbb, 0x70, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x10, 0x3b, 0xbb, 0xb5, 
  0x99, 0x99, 0x99, 0x99, 0xce, 0xee, 0xee, 0xee, 0xee, 0xee, 0xc9, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x10, 0x3b, 0xbb, 0xb8, 
  0x99, 0x99, 0x99, 0x9a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x10, 0x3b, 0xbb, 0xbb, 
  0x99, 0x99, 0x99, 0x99, 0xcd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xb9, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x10, 0x3b, 0xbb, 0xbb, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x10, 0x3b, 0xbb, 0xbb, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x10, 0x3b, 0xbb, 0xbb, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x10, 0x3b, 0xbb, 0xbb, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x10, 0x3b, 0xbb, 0xbb, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x10, 0x3b, 0xbb, 0xbb, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x00, 0x3b, 0xbb, 0xbb, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x96, 0x00, 0x5b, 0xbb, 0xbb, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x94, 0x00, 0x8b, 0xbb, 0xbb, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x60, 0x01, 0xbb, 0xbb, 0xbb, 
  0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x94, 0x00, 0x08, 0xbb, 0xbb, 0xbb, 
  0x99, 0x99, 0x99, 0x99, 0x94, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x23, 0x00, 0x00, 0x7b, 0xbb, 0xbb, 0xbb, 
  0x99, 0x99, 0x99, 0x99, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xbb, 0xbb, 0xbb, 0xbb, 
  0x99, 0x99, 0x99, 0x61, 0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0x57, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 
  0x99, 0x99, 0x96, 0x00, 0x00, 0x7b, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 
  0x99, 0x99, 0x40, 0x00, 0x00, 0x7b, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 
  0x99, 0x94, 0x00, 0x00, 0x00, 0x7b, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 
  0x46, 0x30, 0x00, 0x00, 0x00, 0x7b, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x5b, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1b, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x37, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xbb, 0xbb, 0xbb, 0xbb, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5b, 0xbb, 0xbb, 0xbb, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xbb, 0xbb, 0xbb, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xbb, 0xbb, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7b, 0xbb, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xb7, 
};

const lv_img_dsc_t not_unknown = {
  .header.always_zero = 0,
  .header.w = 42,
  .header.h = 42,
  .data_size = 946,
  .header.cf = LV_IMG_CF_INDEXED_4BIT,
  .data = not_unknown_map,
};

