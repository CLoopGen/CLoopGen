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
    for (y = 0; y < blk_size; y++, out += pitch) {
        out[0] = dc_coeff;
        for (x = 1; x < blk_size; x++) {
            if (x % 2 == 0)
                out[x] = 0;
            else
                out[x] = 0;
        }
    }
}
