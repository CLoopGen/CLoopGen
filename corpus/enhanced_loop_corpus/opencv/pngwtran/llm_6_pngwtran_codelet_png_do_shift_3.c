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
    size_t temp_i;
    unsigned int out, v;
    png_bytep temp_bp = bp;
    for (i = 0; i < row_bytes; i++) {
        v = *temp_bp;
        out = 0;
        int j = shift_start[0];
        while (j > -shift_dec[0]) {  // Forbidden: using while
            if (j > 0)
                out |= v << j;
            else
                out |= (v >> (-j)) & mask;
            j -= shift_dec[0];
        }
        *temp_bp = (png_byte)(out & 255);
        temp_bp++;
    }
}
