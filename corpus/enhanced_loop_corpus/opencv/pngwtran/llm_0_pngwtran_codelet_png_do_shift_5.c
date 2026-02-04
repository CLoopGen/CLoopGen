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
        unsigned int value, v;
        v = ((png_uint_16)(((unsigned int)(*(bp)) << 8) + ((unsigned int)(*((bp) + 1)))));
        value = 0;
        // Unroll inner loop assuming shift_dec[c] is small and constant-friendly
        for (j = shift_start[c]; j > -shift_dec[c]; j -= shift_dec[c]) {
            if (j > 0)
                value |= v << j;
            else
                value |= v >> (-j);
            // Duplicate iteration logic to simulate partial unrolling
            if ((j - shift_dec[c]) > -shift_dec[c]) {
                int j2 = j - shift_dec[c];
                if (j2 > 0)
                    value |= v << j2;
                else
                    value |= v >> (-j2);
            }
        }
        *bp++ = (png_byte)((value >> 8) & 255);
        *bp++ = (png_byte)(value & 255);
    }
}
