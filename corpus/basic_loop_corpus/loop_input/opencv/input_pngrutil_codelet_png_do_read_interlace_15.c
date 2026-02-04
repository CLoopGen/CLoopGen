#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;

typedef struct png_row_info_struct {
    png_uint_32 width;
    size_t rowbytes;
    png_byte color_type;
    png_byte bit_depth;
    png_byte channels;
    png_byte pixel_depth;
} png_row_info;

typedef png_row_info *png_row_infop;
typedef png_byte *png_bytep;

png_row_info _row_info;
png_row_infop row_info = &_row_info;

png_byte *sp_global;
png_bytep sp = NULL;

png_byte *dp_global;
png_bytep dp = NULL;

unsigned int sshift = 0;
unsigned int dshift = 0;
unsigned int s_start = 0;
unsigned int s_end = 0;
int s_inc = 0;
png_uint_32 i = 0;
int jstop = 0;

void init_vars() {
    const size_t data_size = 16777216; // 16MB for ~0.01s runtime estimate

    sp_global = (png_byte*)calloc(data_size, sizeof(png_byte));
    dp_global = (png_byte*)calloc(data_size, sizeof(png_byte));

    if (!sp_global || !dp_global) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    sp = sp_global + data_size - 1;
    dp = dp_global + data_size - 1;

    sshift = 4;
    dshift = 0;
    s_start = 0;
    s_end = 4;
    s_inc = -4;
    jstop = 2;

    row_info->width = 4194304; // 4 million pixels to ensure sufficient work
    row_info->rowbytes = data_size;
    row_info->color_type = 3;
    row_info->bit_depth = 4;
    row_info->channels = 1;
    row_info->pixel_depth = 4;

    for (size_t k = 0; k < data_size; k++) {
        sp_global[k] = (png_byte)(k * 17 % 251);
        dp_global[k] = (png_byte)(k * 31 % 199);
    }
}