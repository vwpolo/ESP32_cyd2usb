/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --font RealMadrid2009.ttf --symbols 12345678890 --format lvgl -o font_rm_2009_14.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "../libraries/lvgl/lvgl.h"
#endif

#ifndef FONT_RM_2009_14
#define FONT_RM_2009_14 1
#endif

#if FONT_RM_2009_14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x39, 0xfb, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6,
    0xf8, 0xe0,

    /* U+0031 "1" */
    0xff, 0xff, 0xfc,

    /* U+0032 "2" */
    0x10, 0xfb, 0xbe, 0x30, 0x61, 0xc7, 0xc, 0x38,
    0xe1, 0xff, 0xf0,

    /* U+0033 "3" */
    0x39, 0xff, 0x18, 0x37, 0xcf, 0x81, 0x83, 0x7,
    0xfb, 0xe0,

    /* U+0034 "4" */
    0xc1, 0x83, 0x6, 0xc, 0xd9, 0xb3, 0x7f, 0xfe,
    0x18, 0x30, 0x60,

    /* U+0035 "5" */
    0xff, 0xff, 0x6, 0xf, 0x9f, 0x81, 0xe3, 0xc6,
    0xf8, 0xe0,

    /* U+0036 "6" */
    0x38, 0xfb, 0x1e, 0xf, 0xdf, 0xf1, 0xe3, 0xc6,
    0xf8, 0xe0,

    /* U+0037 "7" */
    0xff, 0xf8, 0x30, 0xc1, 0x87, 0xc, 0x38, 0x61,
    0xc3, 0x0,

    /* U+0038 "8" */
    0x38, 0xfb, 0x1e, 0x3c, 0x6f, 0x9f, 0x63, 0xc7,
    0x8d, 0xf1, 0xc0,

    /* U+0039 "9" */
    0x38, 0xfb, 0x1e, 0x3c, 0x7f, 0xdf, 0x83, 0xe6,
    0xf8, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 124, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 10, .adv_w = 48, .box_w = 2, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13, .adv_w = 126, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 24, .adv_w = 124, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 34, .adv_w = 125, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 124, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 55, .adv_w = 125, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 65, .adv_w = 127, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 75, .adv_w = 126, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 86, .adv_w = 125, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0}
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

//extern const lv_font_t LV_FONT_MONTSERRAT_14;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t font_rm_2009_14 = {
#else
lv_font_t font_rm_2009_14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 12,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
//    .fallback = &LV_FONT_MONTSERRAT_14,
#endif
    .user_data = NULL,
};



#endif /*#if FONT_RM_2009_14*/
