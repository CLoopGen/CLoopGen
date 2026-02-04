#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef struct png_color_struct {
    png_byte red;
    png_byte green;
    png_byte blue;
} png_color;

typedef png_color *png_colorp;

typedef unsigned short png_uint_16;

typedef char *png_charp;

typedef png_byte *png_bytep;

typedef struct png_text_struct {
    int compression;
    png_charp key;
    png_charp text;
    size_t text_length;
    size_t itxt_length;
    png_charp lang;
    png_charp lang_key;
} png_text;

typedef png_text *png_textp;

typedef struct png_time_struct {
    png_uint_16 year;
    png_byte month;
    png_byte day;
    png_byte hour;
    png_byte minute;
    png_byte second;
} png_time;

typedef struct png_color_8_struct {
    png_byte red;
    png_byte green;
    png_byte blue;
    png_byte gray;
    png_byte alpha;
} png_color_8;

typedef struct png_color_16_struct {
    png_byte index;
    png_uint_16 red;
    png_uint_16 green;
    png_uint_16 blue;
    png_uint_16 gray;
} png_color_16;

typedef int png_int_32;

typedef png_uint_16 *png_uint_16p;

typedef char **png_charpp;

typedef struct png_unknown_chunk_t {
    png_byte name[5];
    png_byte *data;
    size_t size;
    png_byte location;
} png_unknown_chunk;

typedef png_unknown_chunk *png_unknown_chunkp;

typedef struct png_sPLT_entry_struct {
    png_uint_16 red;
    png_uint_16 green;
    png_uint_16 blue;
    png_uint_16 alpha;
    png_uint_16 frequency;
} png_sPLT_entry;

typedef png_sPLT_entry *png_sPLT_entryp;

typedef struct png_sPLT_struct {
    png_charp name;
    png_byte depth;
    png_sPLT_entryp entries;
    png_int_32 nentries;
} png_sPLT_t;

typedef png_sPLT_t *png_sPLT_tp;

typedef png_byte **png_bytepp;

typedef png_int_32 png_fixed_point;

typedef struct png_xy {
    png_fixed_point redx;
    png_fixed_point redy;
    png_fixed_point greenx;
    png_fixed_point greeny;
    png_fixed_point bluex;
    png_fixed_point bluey;
    png_fixed_point whitex;
    png_fixed_point whitey;
} png_xy;

struct png_info_def {
    png_uint_32 width;
    png_uint_32 height;
    png_uint_32 valid;
    size_t rowbytes;
    png_colorp palette;
    png_uint_16 num_palette;
    png_uint_16 num_trans;
    png_byte bit_depth;
    png_byte color_type;
    png_byte compression_type;
    png_byte filter_type;
    png_byte interlace_type;
    png_byte channels;
    png_byte pixel_depth;
    png_byte spare_byte;
    png_byte signature[8];
    png_byte cicp_colour_primaries;
    png_byte cicp_transfer_function;
    png_byte cicp_matrix_coefficients;
    png_byte cicp_video_full_range_flag;
    png_charp iccp_name;
    png_bytep iccp_profile;
    png_uint_32 iccp_proflen;
    int num_text;
    int max_text;
    png_textp text;
    png_time mod_time;
    png_color_8 sig_bit;
    png_bytep trans_alpha;
    png_color_16 trans_color;
    png_color_16 background;
    png_int_32 x_offset;
    png_int_32 y_offset;
    png_byte offset_unit_type;
    png_uint_32 x_pixels_per_unit;
    png_uint_32 y_pixels_per_unit;
    png_byte phys_unit_type;
    png_uint_32 num_exif;
    png_bytep exif;
    png_uint_16p hist;
    png_charp pcal_purpose;
    png_int_32 pcal_X0;
    png_int_32 pcal_X1;
    png_charp pcal_units;
    png_charpp pcal_params;
    png_byte pcal_type;
    png_byte pcal_nparams;
    png_uint_32 free_me;
    png_unknown_chunkp unknown_chunks;
    int unknown_chunks_num;
    png_sPLT_tp splt_palettes;
    int splt_palettes_num;
    png_byte scal_unit;
    png_charp scal_s_width;
    png_charp scal_s_height;
    png_bytepp row_pointers;
    png_xy cHRM;
    png_fixed_point gamma;
    int rendering_intent;
};


typedef struct png_info_def png_info;

typedef png_info *restrict png_inforp;

extern png_inforp info_ptr;
extern png_uint_32 iptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (info_ptr->height > 0) {
        iptr = 0;
        for (; iptr < info_ptr->height; iptr++)
            info_ptr->row_pointers[iptr] = ((void *)0);
    }
}
