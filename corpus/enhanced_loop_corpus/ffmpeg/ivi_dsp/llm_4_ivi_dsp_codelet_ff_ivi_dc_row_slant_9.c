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
    if (blk_size <= 0) return;
    for (x = 0; x < blk_size; x++) {
        out[x] = dc_coeff;
    }
}
