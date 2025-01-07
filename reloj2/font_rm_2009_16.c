/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --no-compress --font RealMadrid2009.ttf --symbols 12345678890 --format lvgl -o font_rm_2009_16.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "../libraries/lvgl/lvgl.h"
#endif

#ifndef FONT_RM_2009_16
#define FONT_RM_2009_16 1
#endif

#if FONT_RM_2009_16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x3c, 0x7e, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,
    0xe7, 0xe7, 0xe7, 0x7e, 0x3c,

    /* U+0031 "1" */
    0xff, 0xff, 0xff, 0xff, 0xfe,

    /* U+0032 "2" */
    0x0, 0x7e, 0x7e, 0xe7, 0x3, 0x7, 0x7, 0xe,
    0x1c, 0x1c, 0x38, 0x70, 0x7f, 0xff,

    /* U+0033 "3" */
    0x3e, 0x3f, 0x98, 0xe0, 0x70, 0x39, 0xf8, 0xfc,
    0xf, 0x3, 0x81, 0xc1, 0xff, 0xef, 0xe0,

    /* U+0034 "4" */
    0xe0, 0xe0, 0xe0, 0xe0, 0xee, 0xee, 0xee, 0xee,
    0xff, 0xff, 0xe, 0xe, 0xe, 0xe,

    /* U+0035 "5" */
    0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xfc, 0xfe, 0xf,
    0x7, 0xe7, 0xe7, 0x7e, 0x3c,

    /* U+0036 "6" */
    0x3c, 0x7e, 0xe7, 0xe0, 0xfc, 0xfe, 0xff, 0xe7,
    0xe7, 0xe7, 0xe7, 0x7e, 0x3c,

    /* U+0037 "7" */
    0xff, 0xfe, 0xe, 0xe, 0x1c, 0x1c, 0x18, 0x38,
    0x30, 0x70, 0x60, 0xe0, 0xe0,

    /* U+0038 "8" */
    0x3c, 0x7e, 0xe7, 0xe7, 0xe7, 0x7e, 0x7e, 0xe7,
    0xe7, 0xe7, 0xe7, 0x7e, 0x3c,

    /* U+0039 "9" */
    0x3c, 0x7e, 0xe7, 0xe7, 0xe7, 0xe7, 0xff, 0x7f,
    0x3f, 0x7, 0xc7, 0xfe, 0x7c
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 142, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13, .adv_w = 55, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 18, .adv_w = 144, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 32, .adv_w = 142, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 142, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 61, .adv_w = 141, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 74, .adv_w = 143, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 145, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 100, .adv_w = 144, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 143, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 48, .range_length = 10, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

//extern const lv_font_t LV_FONT_MONTSERRAT_16;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t font_rm_2009_16 = {
#else
lv_font_t font_rm_2009_16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
  //  .fallback = &LV_FONT_MONTSERRAT_16,
#endif
    .user_data = NULL,
};



#endif /*#if FONT_RM_2009_16*/
