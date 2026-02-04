#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int blk_size;
extern int x;
extern int16_t dc_coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)alloca(blk_size * sizeof(int));
    for (int i = 0; i < blk_size; i++) {
        indices[i] = blk_size - 1 - i; // reverse access pattern
    }
    for (x = 0; x < blk_size; x++) {
        out[indices[x]] = dc_coeff;
    }
}
