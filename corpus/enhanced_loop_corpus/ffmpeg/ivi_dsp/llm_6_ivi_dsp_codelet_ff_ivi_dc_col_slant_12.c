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
    int16_t *row = out;
    for (y = 0; y < blk_size; y++, row += pitch) {
        row[0] = dc_coeff;
        for (x = 1; x < blk_size; x++) {
            row[x] = row[x - 1] - dc_coeff; // Introduce RAW dependency: each element depends on the previous
        }
    }
}
