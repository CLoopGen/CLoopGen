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
    for (y = 0; y < blk_size * blk_size; out += (y % blk_size == blk_size - 1) ? pitch : 0, y++) {
        int idx = y % blk_size;
        out[idx] = dc_coeff + idx - idx;
    }
}
