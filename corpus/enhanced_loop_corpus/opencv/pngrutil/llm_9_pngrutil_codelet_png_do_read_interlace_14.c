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
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < row_info->width; i++) {
        png_byte v;
        int j;
        v = (png_byte)((*sp >> sshift) & 3);

        if (jstop >= 2) {
            for (j = 0; j < jstop - 1; j += 2) {
                unsigned int tmp1 = dp[0] & (16191 >> (6 - dshift));
                tmp1 |= (unsigned int)(v << dshift);
                dp[0] = (png_byte)(tmp1 & 255);

                unsigned int next_dshift = (dshift == s_end) ? s_start : (unsigned int)((int)dshift + s_inc);
                png_bytep next_dp = (dshift == s_end) ? dp - 1 : dp;
                unsigned int tmp2 = next_dp[0] & (16191 >> (6 - next_dshift));
                tmp2 |= (unsigned int)(v << next_dshift);
                next_dp[0] = (png_byte)(tmp2 & 255);

                if (dshift == s_end) {
                    dshift = s_start;
                    dp--;
                } else
                    dshift = (unsigned int)((int)dshift + s_inc);

                if (dshift == s_end) {
                    dshift = s_start;
                    dp--;
                } else
                    dshift = (unsigned int)((int)dshift + s_inc);
            }
            if (j < jstop) {
                unsigned int tmp = *dp & (16191 >> (6 - dshift));
                tmp |= (unsigned int)(v << dshift);
                *dp = (png_byte)(tmp & 255);
                if (dshift == s_end) {
                    dshift = s_start;
                    dp--;
                } else
                    dshift = (unsigned int)((int)dshift + s_inc);
            }
        } else {
            for (j = 0; j < jstop; j++) {
                unsigned int tmp = *dp & (16191 >> (6 - dshift));
                tmp |= (unsigned int)(v << dshift);
                *dp = (png_byte)(tmp & 255);
                if (dshift == s_end) {
                    dshift = s_start;
                    dp--;
                } else
                    dshift = (unsigned int)((int)dshift + s_inc);
            }
        }

        if (sshift == s_end) {
            sshift = s_start;
            sp--;
        } else
            sshift = (unsigned int)((int)sshift + s_inc);
    }
}
