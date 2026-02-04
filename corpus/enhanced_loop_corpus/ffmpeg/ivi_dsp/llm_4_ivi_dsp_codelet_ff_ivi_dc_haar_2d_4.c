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
    if (blk_size <= 0) return;
    for (y = 0; y < blk_size; y++, out += pitch) {
        int16_t *row = out;
        for (x = 0; x < blk_size; x++) {
            row[x] = dc_coeff;
        }
    }
}
