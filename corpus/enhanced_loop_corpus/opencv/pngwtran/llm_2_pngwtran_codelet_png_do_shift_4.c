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
    for (i = 0; i < istop; i += 2, bp += 2) {
        unsigned int c = (i % channels);
        int j;
        unsigned int v, out;
        
        // Process current element
        if (i < istop) {
            v = *bp;
            out = 0;
            for (j = shift_start[c]; j > -shift_dec[c]; j -= shift_dec[c]) {
                if (j > 0)
                    out |= v << j;
                else
                    out |= v >> (-j);
            }
            *bp = (png_byte)(out & 255);
        }

        // Process next element if within bounds
        if (i + 1 < istop) {
            png_bytep bp_next = bp + 1;
            unsigned int c_next = ((i + 1) % channels);
            v = *bp_next;
            out = 0;
            for (j = shift_start[c_next]; j > -shift_dec[c_next]; j -= shift_dec[c_next]) {
                if (j > 0)
                    out |= v << j;
                else
                    out |= v >> (-j);
            }
            *bp_next = (png_byte)(out & 255);
        }
    }
}
