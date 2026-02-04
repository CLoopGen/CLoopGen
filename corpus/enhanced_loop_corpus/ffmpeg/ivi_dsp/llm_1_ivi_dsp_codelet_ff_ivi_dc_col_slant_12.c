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
if (blk_size > 0) {
    for (y = 0; y < blk_size; y++) {
        int16_t *row = &out[y * pitch];
        row[0] = dc_coeff;
        for (x = 1; x < blk_size; x++) {
            for (int z = 0; z < 1; z++) { // Artificially increase nesting depth
                row[x] = 0;
            }
        }
    }
}
}
