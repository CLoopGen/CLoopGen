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
    int y, x;
    ptrdiff_t offset = 0;
    for (y = 0; y < blk_size; y++, offset += pitch) {
        int16_t *row = out + offset;
        for (x = 0; x < blk_size; x += 4) {
            row[x]     = dc_coeff;
            if (x+1 < blk_size) row[x+1] = dc_coeff;
            if (x+2 < blk_size) row[x+2] = dc_coeff;
            if (x+3 < blk_size) row[x+3] = dc_coeff;
        }
    }
}
