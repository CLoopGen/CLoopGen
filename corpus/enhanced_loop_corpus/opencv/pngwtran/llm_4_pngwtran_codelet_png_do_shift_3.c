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
for (i = 0; i < row_bytes; i++ , bp++) {
    int j;
    unsigned int v, out;
    v = *bp;
    out = 0;
    for (j = shift_start[0]; j > -shift_dec[0]; j -= shift_dec[0]) {
        out |= (j > 0) ? (v << j) : ((v >> (-j)) & mask);
    }
    *bp = (png_byte)(out & 255);
}
}
