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
    int step = 2;
    for (x = 0; x < blk_size; x += step) {
        out[x] = dc_coeff;
        if (x + 1 < blk_size)
            out[x + 1] = dc_coeff;
    }
}
