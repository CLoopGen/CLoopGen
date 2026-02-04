#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

typedef unsigned short png_uint_16;

extern png_bytep row;
extern int shift_start[4];
extern int shift_dec[4];
extern unsigned int channels;
extern png_bytep bp;
extern png_uint_32 i;
extern png_uint_32 istop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
unsigned int prev_channels = 0;
for (bp = row , i = 0; i < istop; i++) {
    unsigned int c = (i + prev_channels) % channels;
    int j;
    unsigned int value = 0, v;
    v = ((png_uint_16)(((unsigned int)(*(bp)) << 8) + ((unsigned int)(*((bp) + 1)))));
    for (j = shift_start[c]; j > -shift_dec[c]; j -= shift_dec[c]) {
        value |= (j > 0) ? (v << j) : (v >> (-j));
    }
    prev_channels = channels; // Introduce loop-carried dependency via 'prev_channels'
    *bp++ = (png_byte)((value >> 8) & 255);
    *bp++ = (png_byte)(value & 255);
}
}
