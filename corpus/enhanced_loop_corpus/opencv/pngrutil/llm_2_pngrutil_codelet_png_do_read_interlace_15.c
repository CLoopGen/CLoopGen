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
extern png_uint_32 i;
extern int jstop;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of decrementing sp and dp, we precompute the starting pointers
    // and access elements consecutively using pointer arithmetic with increments.
    png_bytep sp_start = sp - (row_info->width - 1) * (s_inc == 1 ? 0 : 1);
    png_bytep dp_start = dp - (row_info->width - 1) * (s_inc == 1 ? 0 : 1);
    unsigned int local_sshift = sshift;
    unsigned int local_dshift = dshift;

    for (i = 0; i < row_info->width; i++) {
        png_byte v = (png_byte)((*(sp_start + i) >> local_sshift) & 15);
        int j;
        for (j = 0; j < jstop; j++) {
            unsigned int tmp = *(dp_start + i) & (3855 >> (4 - local_dshift));
            tmp |= (unsigned int)(v << local_dshift);
            *(dp_start + i) = (png_byte)(tmp & 255);
            if (local_dshift == s_end) {
                local_dshift = s_start;
            } else {
                local_dshift = (unsigned int)((int)local_dshift + s_inc);
            }
        }
        if (local_sshift == s_end) {
            local_sshift = s_start;
        } else {
            local_sshift = (unsigned int)((int)local_sshift + s_inc);
        }
    }
}
