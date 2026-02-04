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
    v = (png_byte)((*(sp + (i << 1)) >> sshift) & 3);
    for (j = 0; j < jstop; j++) {
        unsigned int tmp = *(dp - j) & (16191 >> (6 - ((dshift + j) & 7)));
        tmp |= (unsigned int)(v << ((dshift + j) & 7));
        *(dp - j) = (png_byte)(tmp & 255);
    }
    sshift = (sshift == s_end) ? s_start : ((sshift + s_inc) & 7);
    dp--;
}
}
