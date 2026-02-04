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



void loop() {
    // Strided memory access: process every 'channels'-th element in each pass
    for (unsigned int c = 0; c < channels; c++) {
        png_bytep bp_c = bp + c;
        for (png_uint_32 k = 0; i + k * channels < istop; k++, bp_c += channels) {
            unsigned int idx = i + k * channels;
            unsigned int current_c = idx % channels;
            int j;
            unsigned int v, out;
            v = *bp_c;
            out = 0;
            for (j = shift_start[current_c]; j > -shift_dec[current_c]; j -= shift_dec[current_c]) {
                if (j > 0)
                    out |= v << j;
                else
                    out |= v >> (-j);
            }
            *bp_c = (png_byte)(out & 255);
        }
    }
}
