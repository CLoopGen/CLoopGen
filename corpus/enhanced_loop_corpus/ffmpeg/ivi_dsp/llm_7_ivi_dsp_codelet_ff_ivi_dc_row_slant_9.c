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
    if (blk_size > 0) {
        out[0] = dc_coeff;
        for (x = 1; x < blk_size; x++) {
            out[x] = out[x - 1];
        }
    }
}
