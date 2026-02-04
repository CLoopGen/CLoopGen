#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift_start[4];
extern int shift_dec[4];
extern unsigned int channels;
extern png_bytep bp;
extern png_uint_32 i;
extern png_uint_32 istop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < istop; i++ , bp++) {
    unsigned int c = i % channels;
    int j = shift_start[c];
    unsigned int v = *bp;
    unsigned int out = 0;
    if (shift_dec[c] > 0) {
        while (j > -shift_dec[c]) {
            if (j > 0)
                out |= v << j;
            else
                out |= v >> (-j);
            j -= shift_dec[c];
        }
    } else {
        out = v;
    }
    *bp = (png_byte)(out & 255);
}
}
