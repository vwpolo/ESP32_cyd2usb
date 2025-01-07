#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMAGE_ARROW
#define LV_ATTRIBUTE_IMAGE_ARROW
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMAGE_ARROW uint8_t arrow_map[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x00, 0x67, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x44, 0x03, 0x01, 0x03, 0xf4, 0x02, 0x01, 0x02, 0xf4, 0x07, 0x03, 0x07, 0x49, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x08, 0x05, 0x08, 0xa9, 0x08, 0x04, 0x08, 0xff, 0x08, 0x04, 0x08, 0xff, 0x07, 0x04, 0x07, 0xaf, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x06, 0x2a, 0x08, 0x04, 0x08, 0xe7, 0x09, 0x05, 0x09, 0xff, 0x09, 0x05, 0x09, 0xff, 0x09, 0x04, 0x09, 0xe9, 0x06, 0x00, 0x06, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x04, 0x09, 0x75, 0x09, 0x05, 0x09, 0xfe, 0x08, 0x05, 0x08, 0xff, 0x08, 0x05, 0x08, 0xff, 0x09, 0x05, 0x09, 0xfe, 0x09, 0x04, 0x09, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x08, 0x04, 0x08, 0xc7, 0x08, 0x04, 0x08, 0xff, 0x07, 0x04, 0x07, 0xff, 0x07, 0x04, 0x07, 0xff, 0x08, 0x05, 0x08, 0xff, 0x09, 0x05, 0x09, 0xc6, 0x0f, 0x00, 0x0f, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x04, 0x08, 0x3f, 0x08, 0x04, 0x08, 0xf6, 0x08, 0x04, 0x08, 0xff, 0x02, 0x01, 0x02, 0xfe, 0x03, 0x02, 0x03, 0xfe, 0x08, 0x05, 0x08, 0xff, 0x08, 0x04, 0x08, 0xf6, 0x07, 0x04, 0x07, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x09, 0x03, 0x09, 0x95, 0x09, 0x05, 0x09, 0xff, 0x07, 0x04, 0x07, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x01, 0x02, 0xfe, 0x08, 0x04, 0x08, 0xff, 0x09, 0x05, 0x09, 0xfe, 0x08, 0x03, 0x08, 0x9b, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x0a, 0x1a, 0x08, 0x03, 0x08, 0xdc, 0x08, 0x05, 0x08, 0xff, 0x05, 0x03, 0x05, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x07, 0x04, 0x07, 0xff, 0x08, 0x04, 0x08, 0xff, 0x09, 0x03, 0x09, 0xde, 0x08, 0x00, 0x08, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x06, 0x08, 0x5b, 0x08, 0x04, 0x08, 0xfd, 0x08, 0x04, 0x08, 0xff, 0x02, 0x01, 0x02, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x02, 0x01, 0x02, 0xff, 0x07, 0x03, 0x07, 0xff, 0x08, 0x04, 0x08, 0xfd, 0x08, 0x03, 0x08, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x04, 0x09, 0xb0, 0x08, 0x04, 0x08, 0xff, 0x06, 0x03, 0x06, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x01, 0x01, 0xff, 0x08, 0x04, 0x08, 0xff, 0x08, 0x04, 0x08, 0xb5, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x05, 0x0b, 0x30, 0x07, 0x04, 0x07, 0xef, 0x08, 0x04, 0x08, 0xff, 0x02, 0x01, 0x02, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x06, 0x03, 0x06, 0xff, 0x08, 0x04, 0x08, 0xf0, 0x0b, 0x05, 0x0b, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x08, 0x02, 0x08, 0x7f, 0x09, 0x05, 0x09, 0xfe, 0x07, 0x04, 0x07, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xfd, 0x03, 0x01, 0x03, 0xff, 0x08, 0x04, 0x08, 0xfe, 0x08, 0x04, 0x08, 0x7e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x0f, 0x11, 0x09, 0x04, 0x09, 0xd1, 0x09, 0x05, 0x09, 0xff, 0x06, 0x03, 0x06, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xfd, 0x01, 0x00, 0x01, 0xfe, 0x07, 0x04, 0x07, 0xff, 0x07, 0x04, 0x07, 0xcf, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x07, 0x47, 0x08, 0x04, 0x08, 0xfa, 0x08, 0x04, 0x08, 0xff, 0x04, 0x02, 0x04, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xfd, 0x00, 0x00, 0x00, 0xfd, 0x07, 0x04, 0x07, 0xff, 0x08, 0x04, 0x08, 0xfa, 0x07, 0x03, 0x07, 0x4d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x08, 0x05, 0x08, 0xa0, 0x09, 0x05, 0x09, 0xff, 0x08, 0x04, 0x08, 0xff, 0x01, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x07, 0x04, 0x07, 0xff, 0x09, 0x05, 0x09, 0xff, 0x08, 0x05, 0x08, 0xa5, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x08, 0x21, 0x08, 0x04, 0x08, 0xe7, 0x08, 0x05, 0x08, 0xff, 0x05, 0x02, 0x05, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x06, 0x03, 0x06, 0xfe, 0x08, 0x05, 0x08, 0xff, 0x08, 0x04, 0x08, 0xe7, 0x08, 0x00, 0x08, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x05, 0x07, 0x6d, 0x09, 0x04, 0x09, 0xfe, 0x08, 0x04, 0x08, 0xff, 0x02, 0x01, 0x02, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x01, 0x02, 0xfe, 0x08, 0x04, 0x08, 0xff, 0x09, 0x05, 0x09, 0xfe, 0x07, 0x05, 0x07, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x08, 0x04, 0x08, 0xc2, 0x08, 0x04, 0x08, 0xff, 0x08, 0x04, 0x08, 0xff, 0x01, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x06, 0x03, 0x06, 0xfe, 0x09, 0x05, 0x09, 0xff, 0x08, 0x04, 0x08, 0xc0, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x05, 0x09, 0x36, 0x08, 0x04, 0x08, 0xf7, 0x08, 0x05, 0x08, 0xff, 0x05, 0x02, 0x05, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x03, 0x01, 0x03, 0xfe, 0x08, 0x04, 0x08, 0xff, 0x09, 0x04, 0x09, 0xf6, 0x08, 0x04, 0x08, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x04, 0x07, 0x8b, 0x09, 0x05, 0x09, 0xff, 0x08, 0x04, 0x08, 0xff, 0x02, 0x01, 0x02, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x01, 0xfe, 0x08, 0x04, 0x08, 0xff, 0x09, 0x05, 0x09, 0xff, 0x09, 0x04, 0x09, 0x90, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x03, 0x08, 0xde, 0x08, 0x04, 0x08, 0xff, 0x06, 0x03, 0x06, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x01, 0xfe, 0x03, 0x01, 0x03, 0xff, 0x02, 0x01, 0x02, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x07, 0x04, 0x07, 0xff, 0x09, 0x05, 0x09, 0xff, 0x08, 0x03, 0x08, 0xde, 0x0c, 0x00, 0x0c, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x03, 0x06, 0x50, 0x08, 0x04, 0x08, 0xfd, 0x08, 0x04, 0x08, 0xff, 0x02, 0x00, 0x02, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x03, 0x01, 0x03, 0xfe, 0x08, 0x04, 0x08, 0xfe, 0x08, 0x04, 0x08, 0xff, 0x08, 0x04, 0x08, 0xff, 0x06, 0x03, 0x06, 0xff, 0x01, 0x01, 0x01, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x04, 0x02, 0x04, 0xff, 0x08, 0x04, 0x08, 0xff, 0x08, 0x04, 0x08, 0xfd, 0x09, 0x03, 0x09, 0x56, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x07, 0x04, 0x07, 0xae, 0x08, 0x04, 0x08, 0xff, 0x03, 0x01, 0x03, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x03, 0x01, 0x03, 0xff, 0x08, 0x04, 0x08, 0xfe, 0x09, 0x05, 0x09, 0xff, 0x09, 0x04, 0x09, 0xfe, 0x09, 0x05, 0x09, 0xfe, 0x08, 0x04, 0x08, 0xff, 0x07, 0x04, 0x07, 0xfe, 0x05, 0x02, 0x05, 0xfd, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x01, 0xff, 0x07, 0x04, 0x07, 0xff, 0x09, 0x05, 0x09, 0xff, 0x09, 0x04, 0x09, 0xb1, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x07, 0x23, 0x09, 0x04, 0x09, 0xf2, 0x08, 0x04, 0x08, 0xff, 0x02, 0x01, 0x02, 0xfe, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x03, 0x01, 0x03, 0xff, 0x08, 0x04, 0x08, 0xff, 0x09, 0x05, 0x09, 0xff, 0x08, 0x04, 0x08, 0xf8, 0x08, 0x03, 0x08, 0x9c, 0x08, 0x03, 0x08, 0x98, 0x08, 0x04, 0x08, 0xf7, 0x09, 0x05, 0x09, 0xff, 0x08, 0x04, 0x08, 0xfe, 0x06, 0x03, 0x06, 0xfd, 0x01, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0xfe, 0x05, 0x02, 0x05, 0xfe, 0x08, 0x04, 0x08, 0xff, 0x08, 0x04, 0x08, 0xf1, 0x07, 0x07, 0x07, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x04, 0x08, 0x7a, 0x09, 0x04, 0x09, 0xfe, 0x08, 0x04, 0x08, 0xff, 0x02, 0x01, 0x02, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x05, 0x03, 0x05, 0xff, 0x08, 0x04, 0x08, 0xff, 0x09, 0x05, 0x09, 0xff, 0x09, 0x05, 0x09, 0xec, 0x07, 0x05, 0x07, 0x6f, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x09, 0x07, 0x05, 0x07, 0x6b, 0x08, 0x04, 0x08, 0xed, 0x09, 0x05, 0x09, 0xff, 0x08, 0x04, 0x08, 0xff, 0x06, 0x03, 0x06, 0xfe, 0x01, 0x00, 0x01, 0xfe, 0x01, 0x00, 0x01, 0xfe, 0x08, 0x04, 0x08, 0xff, 0x09, 0x05, 0x09, 0xfe, 0x08, 0x04, 0x08, 0x78, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x04, 0x09, 0xd1, 0x09, 0x05, 0x09, 0xff, 0x07, 0x04, 0x07, 0xff, 0x02, 0x01, 0x02, 0xff, 0x05, 0x03, 0x05, 0xfe, 0x08, 0x04, 0x08, 0xff, 0x09, 0x04, 0x09, 0xfe, 0x08, 0x03, 0x08, 0xdf, 0x06, 0x03, 0x06, 0x50, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x09, 0x03, 0x09, 0x51, 0x08, 0x03, 0x08, 0xdc, 0x09, 0x05, 0x09, 0xfe, 0x08, 0x04, 0x08, 0xff, 0x07, 0x03, 0x07, 0xfe, 0x01, 0x00, 0x01, 0xfe, 0x06, 0x03, 0x06, 0xff, 0x09, 0x05, 0x09, 0xff, 0x07, 0x04, 0x07, 0xce, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x08, 0x04, 0x08, 0x3d, 0x08, 0x04, 0x08, 0xfc, 0x09, 0x05, 0x09, 0xff, 0x08, 0x04, 0x08, 0xff, 0x08, 0x04, 0x08, 0xff, 0x08, 0x04, 0x08, 0xff, 0x08, 0x04, 0x08, 0xfd, 0x08, 0x04, 0x08, 0xc4, 0x05, 0x05, 0x05, 0x2f, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x06, 0x06, 0x2c, 0x08, 0x04, 0x08, 0xc0, 0x08, 0x04, 0x08, 0xfd, 0x08, 0x04, 0x08, 0xff, 0x07, 0x04, 0x07, 0xff, 0x08, 0x04, 0x08, 0xff, 0x09, 0x05, 0x09, 0xff, 0x08, 0x04, 0x08, 0xfb, 0x07, 0x04, 0x07, 0x44, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x01, 0x08, 0x03, 0x08, 0x9a, 0x09, 0x05, 0x09, 0xff, 0x09, 0x05, 0x09, 0xff, 0x09, 0x05, 0x09, 0xff, 0x09, 0x05, 0x09, 0xff, 0x08, 0x04, 0x08, 0xfb, 0x08, 0x05, 0x08, 0xa3, 0x0a, 0x00, 0x0a, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x0a, 0x19, 0x08, 0x05, 0x08, 0xa4, 0x09, 0x04, 0x09, 0xfa, 0x09, 0x05, 0x09, 0xff, 0x09, 0x05, 0x09, 0xff, 0x09, 0x05, 0x09, 0xff, 0x09, 0x05, 0x09, 0xff, 0x08, 0x03, 0x08, 0x9e, 0x00, 0x00, 0x00, 0x01, 
  0x00, 0x00, 0x00, 0x15, 0x09, 0x04, 0x09, 0xed, 0x09, 0x05, 0x09, 0xff, 0x09, 0x05, 0x09, 0xff, 0x08, 0x04, 0x08, 0xfe, 0x08, 0x04, 0x08, 0xf4, 0x06, 0x04, 0x06, 0x7e, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x06, 0x04, 0x06, 0x7a, 0x08, 0x04, 0x08, 0xf4, 0x09, 0x05, 0x09, 0xff, 0x09, 0x05, 0x09, 0xff, 0x09, 0x05, 0x09, 0xff, 0x08, 0x04, 0x08, 0xec, 0x00, 0x00, 0x00, 0x15, 
  0x08, 0x03, 0x08, 0x60, 0x09, 0x04, 0x09, 0xfe, 0x09, 0x04, 0x09, 0xfe, 0x09, 0x04, 0x09, 0xfe, 0x09, 0x04, 0x09, 0xe9, 0x09, 0x03, 0x09, 0x58, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x09, 0x03, 0x09, 0x59, 0x08, 0x04, 0x08, 0xe6, 0x09, 0x05, 0x09, 0xfe, 0x09, 0x05, 0x09, 0xff, 0x08, 0x04, 0x08, 0xfe, 0x08, 0x03, 0x08, 0x5e, 
  0x08, 0x02, 0x08, 0x7c, 0x09, 0x05, 0x09, 0xff, 0x09, 0x04, 0x09, 0xfe, 0x08, 0x04, 0x08, 0xd4, 0x0b, 0x05, 0x0b, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x2f, 0x09, 0x04, 0x09, 0xd0, 0x09, 0x04, 0x09, 0xfe, 0x09, 0x05, 0x09, 0xff, 0x08, 0x02, 0x08, 0x78, 
  0x0c, 0x00, 0x0c, 0x16, 0x08, 0x03, 0x08, 0x9d, 0x08, 0x03, 0x08, 0x9b, 0x09, 0x00, 0x09, 0x1b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x0a, 0x1a, 0x08, 0x03, 0x08, 0x9c, 0x08, 0x05, 0x08, 0xa4, 0x0a, 0x00, 0x0a, 0x19, 
};

const lv_image_dsc_t arrow = {
  .header = {
      .magic = LV_IMAGE_HEADER_MAGIC,
      .cf = LV_COLOR_FORMAT_ARGB8888,
      .flags = 0,
      .w = 26,
      .h = 33,
      .reserved_2 = 0
  },
  .data_size = sizeof(arrow_map),
  .data = arrow_map,
  .reserved = NULL
};
