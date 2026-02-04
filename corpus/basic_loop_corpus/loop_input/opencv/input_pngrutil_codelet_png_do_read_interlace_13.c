#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
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

// Define all external variables
static png_row_info row_info_data;
png_row_infop row_info = &row_info_data;

static png_byte *sp_global;
static png_byte *dp_global;
png_bytep sp = NULL;
png_bytep dp = NULL;

unsigned int sshift;
unsigned int dshift;
unsigned int s_start;
unsigned int s_end;
int s_inc;
int jstop;
png_byte v;
png_uint_32 i;
int j;

void init_vars() {
    // Set image dimensions and parameters to control data size (~64 MB target)
    row_info->width = 16777216;  // ~16.7 million pixels
    row_info->rowbytes = (row_info->width * 1 + 7) / 8;  // 1 bit per pixel, byte-aligned
    row_info->color_type = 0;
    row_info->bit_depth = 1;
    row_info->channels = 1;
    row_info->pixel_depth = 1;

    // Allocate input and output buffers with sufficient size
    size_t buffer_size = row_info->rowbytes + 16;  // Extra padding to prevent overflow

    sp_global = (png_byte*)calloc(buffer_size, sizeof(png_byte));
    dp_global = (png_byte*)calloc(buffer_size, sizeof(png_byte));

    if (!sp_global || !dp_global) {
        exit(1);
    }

    // Initialize pointers
    sp = sp_global + buffer_size - 1;  // Start near the end to allow -- during loop
    dp = dp_global + buffer_size - 1;

    // Bit shift configuration: packing 1-bit values into bytes
    s_start = 7;
    s_end = 0;
    dshift = 7;
    sshift = 7;
    s_inc = -1;
    jstop = 1;  // Each source bit maps to one destination operation

    // Ensure initial values are within bounds
    v = 0;
    i = 0;
    j = 0;

    // Initialize some sample data in sp_global
    for (size_t k = 0; k < buffer_size - 16; k++) {
        sp_global[k] = (png_byte)(rand() & 255);
    }
}