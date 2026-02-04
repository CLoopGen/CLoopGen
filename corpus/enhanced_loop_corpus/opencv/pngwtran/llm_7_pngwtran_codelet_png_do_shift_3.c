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
    size_t local_i;
    png_bytep temp_bp = bp;
    unsigned int temp_mask = mask;
    for (local_i = 0; local_i < row_bytes; local_i++, temp_bp++) {
        int j;
        unsigned int v = *(temp_bp); 
        unsigned int out = 0;
        for (j = shift_start[0]; j > -shift_dec[0]; j -= shift_dec[0]) {
            unsigned int shifted;
            if (j > 0)
                shifted = v << j;
            else
                shifted = (v >> (-j)) & temp_mask;
            out = out | shifted;  // Introduce temporary to break direct WAW on 'out'
        }
        *temp_bp = (png_byte)(out & 255U);
    }
    i = local_i;  // Reconcile final value for external use
}
