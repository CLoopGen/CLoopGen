#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern ptrdiff_t pitch;
extern int blk_size;
extern int x;
extern int y;
extern int16_t dc_coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < blk_size; out += pitch, y++) {
        int16_t temp = dc_coeff + 1;
        for (x = 0; x < blk_size; x++) {
            out[x] = temp * 2 - 1;
        }
    }
}
