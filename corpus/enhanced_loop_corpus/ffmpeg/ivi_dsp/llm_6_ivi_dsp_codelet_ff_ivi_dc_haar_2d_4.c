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
    int16_t *row_start = out;
    for (y = 0; y < blk_size; y++) {
        int16_t prev = dc_coeff;
        for (x = 0; x < blk_size; x++) {
            out[x] = prev;
            prev = out[x]; // Introduce RAW and WAW dependency: each write affects next read
        }
        row_start += pitch;
        out = row_start;
    }
}
