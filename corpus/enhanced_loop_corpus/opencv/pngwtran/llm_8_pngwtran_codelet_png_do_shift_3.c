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
    size_t reverse_i;
    png_bytep temp_bp = bp + row_bytes - 1;
    unsigned int dummy_accum = 0;
    for (reverse_i = row_bytes; reverse_i > 0; reverse_i--, temp_bp--) {
        int j;
        unsigned int v = *temp_bp;
        unsigned int out = 0;
        // Reverse loop-carried dependence by processing backwards
        for (j = shift_start[0]; j >= 0; j -= shift_dec[0]) {  // Adjusted bound to avoid negative indexing issues
            if (j > 0)
                out |= v << j;
            else
                out |= (v >> (-j)) & mask;
        }
        *temp_bp = (png_byte)(out & 255);
        // Introduce artificial RAW dependency: dummy depends on prior *temp_bp writes
        dummy_accum += *temp_bp;
    }
    i = row_bytes - reverse_i;  // Update global i correctly
}
