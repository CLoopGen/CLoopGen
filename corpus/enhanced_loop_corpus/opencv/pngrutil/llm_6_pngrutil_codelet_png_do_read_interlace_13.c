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
    png_uint_32 temp_width = row_info->width;
    unsigned int local_sshift = sshift;
    unsigned int local_dshift = dshift;
    png_bytep local_sp = sp;
    png_bytep local_dp = dp;
    for (i = 0; i < temp_width; i++) {
        v = (png_byte)((*local_sp >> local_sshift) & 1);
        unsigned int inner_shift = local_dshift;
        png_bytep inner_dp = local_dp;
        for (j = 0; j < jstop; j++) {
            unsigned int tmp = *inner_dp & (32639 >> (7 - inner_shift));
            tmp |= (unsigned int)(v << inner_shift);
            *inner_dp = (png_byte)(tmp & 255);
            if (inner_shift == s_end) {
                inner_shift = s_start;
                inner_dp--;
            } else
                inner_shift = (unsigned int)((int)inner_shift + s_inc);
        }
        local_dp = inner_dp;
        if (local_sshift == s_end) {
            local_sshift = s_start;
            local_sp--;
        } else
            local_sshift = (unsigned int)((int)local_sshift + s_inc);
    }
    dp = local_dp;
    sp = local_sp;
    sshift = local_sshift;
    dshift = local_dshift;
}
