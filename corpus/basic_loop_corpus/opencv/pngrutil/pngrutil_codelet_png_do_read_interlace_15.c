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
for (i = 0; i < row_info->width; i++) {
    png_byte v = (png_byte)((*sp >> sshift) & 15);
    int j;
    for (j = 0; j < jstop; j++) {
        unsigned int tmp = *dp & (3855 >> (4 - dshift));
        tmp |= (unsigned int)(v << dshift);
        *dp = (png_byte)(tmp & 255);
        if (dshift == s_end) {
            dshift = s_start;
            dp--;
        } else
            dshift = (unsigned int)((int)dshift + s_inc);
    }
    if (sshift == s_end) {
        sshift = s_start;
        sp--;
    } else
        sshift = (unsigned int)((int)sshift + s_inc);
}

}
