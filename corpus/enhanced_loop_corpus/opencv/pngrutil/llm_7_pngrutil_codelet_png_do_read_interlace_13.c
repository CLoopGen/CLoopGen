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

extern png_row_infop row_info;
extern png_bytep sp;
extern png_bytep dp;
extern unsigned int sshift;
extern unsigned int dshift;
extern unsigned int s_start;
extern unsigned int s_end;
extern int s_inc;
extern int jstop;
extern png_byte v;
extern png_uint_32 i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < row_info->width; i++) {
        png_byte local_v = (png_byte)((sp[i >> 3] >> (7 - (i & 7))) & 1);
        unsigned int bit_index = dshift;
        png_bytep current_dp = dp - (i >> 3);
        for (j = 0; j < jstop; j++) {
            unsigned int mask = (32639 >> (7 - bit_index));
            unsigned int val = (local_v << bit_index);
            unsigned int merged = (*current_dp & mask) | val;
            *current_dp = (png_byte)(merged & 255);
            bit_index = (bit_index == s_end) ? s_start : bit_index + s_inc;
            if (bit_index == s_start) current_dp--;
        }
        dshift = bit_index;
        if ((i & 7) == 7) {
            sp--;
        }
    }
}
