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



void loop(){
    png_uint_32 i;
    for (i = 0; i < row_info->width; i += 2) {
        png_byte v1 = (png_byte)((sp[0] >> sshift) & 15);
        unsigned int next_sshift = (sshift == s_end) ? s_start : (unsigned int)((int)sshift + s_inc);
        png_byte v2 = (i + 1 < row_info->width) ? (png_byte)((sp[(next_sshift > sshift) ? 0 : -1] >> next_sshift) & 15) : v1;

        int j;
        for (j = 0; j < jstop; j++) {
            unsigned int tmp1 = *dp & (3855 >> (4 - dshift));
            tmp1 |= (unsigned int)(v1 << dshift);
            *dp = (png_byte)(tmp1 & 255);

            unsigned int next_dshift = (dshift == s_end) ? s_start : (unsigned int)((int)dshift + s_inc);
            if (next_dshift != s_start) {
                unsigned int tmp2 = *(dp - (next_dshift > dshift ? 0 : 1)) & (3855 >> (4 - next_dshift));
                tmp2 |= (unsigned int)(v2 << next_dshift);
                *(dp - (next_dshift > dshift ? 0 : 1)) = (png_byte)(tmp2 & 255);
            }

            if (dshift == s_end) {
                dshift = s_start;
                dp--;
            } else {
                dshift = next_dshift;
            }
        }

        if (sshift == s_end) {
            sshift = s_start;
            sp--;
        } else {
            sshift = next_sshift;
        }
    }
}
