#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern int shift_start[4];
extern int shift_dec[4];
extern png_bytep bp;
extern size_t i;
extern unsigned int mask;
extern size_t row_bytes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    int j;
    for (i = 0; i < row_bytes; i++) {
        unsigned int v, out;
        v = bp[i];
        out = 0;
        for (j = shift_start[0]; j > -shift_dec[0]; j -= shift_dec[0]) {
            unsigned int shifted;
            if (j > 0) {
                shifted = v << j;
            } else {
                shifted = (v >> (-j)) & mask;
            }
            out |= shifted;
        }
        bp[i] = (png_byte)(out & 255);
    }
}
