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
    size_t *indices = (size_t*)malloc(row_bytes * sizeof(size_t));
    if (!indices) return;
    for (size_t temp_i = 0; temp_i < row_bytes; temp_i++) {
        indices[temp_i] = row_bytes - 1 - temp_i; // Reverse order index array (indirect access)
    }
    for (i = 0; i < row_bytes; i++) {
        int j;
        unsigned int v, out;
        size_t pos = indices[i]; // Indirect access via precomputed indices
        v = bp[pos];
        out = 0;
        for (j = shift_start[0]; j > -shift_dec[0]; j -= shift_dec[0]) {
            if (j > 0)
                out |= v << j;
            else
                out |= (v >> (-j)) & mask;
        }
        bp[pos] = (png_byte)(out & 255);
    }
    free(indices);
}
