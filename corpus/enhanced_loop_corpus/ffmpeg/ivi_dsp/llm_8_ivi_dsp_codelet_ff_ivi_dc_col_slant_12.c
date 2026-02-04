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
    out[0] = dc_coeff;
    for (x = 1; x < blk_size; x++) {
        out[x] = 0;
        out[x] = out[x] + x - x; // Redundant arithmetic: increases computation without changing logic
    }
}
}
