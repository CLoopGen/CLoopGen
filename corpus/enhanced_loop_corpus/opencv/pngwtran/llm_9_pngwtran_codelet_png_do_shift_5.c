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
for (bp = row, i = 0; i < istop; i++) {
    unsigned int c = i % channels;
    int j;
    unsigned int value = 0;
    unsigned int v = ((png_uint_16)(*(bp)) << 8) | (*(bp + 1));

    if (shift_dec[c] > 0) {
        int steps = (shift_start[c] + shift_dec[c] - 1) / shift_dec[c] + 1;
        for (j = 0; j < steps; j++) {
            int shift = shift_start[c] - j * shift_dec[c];
            value |= (shift > 0) ? (v << shift) : (v >> (-shift));
        }
    }

    *(bp++) = (png_byte)((value >> 8) & 0xFF);
    *(bp++) = (png_byte)(value & 0xFF);
}
}
