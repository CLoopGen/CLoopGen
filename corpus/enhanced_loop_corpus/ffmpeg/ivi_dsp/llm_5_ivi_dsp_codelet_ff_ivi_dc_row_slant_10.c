#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern ptrdiff_t pitch;
extern int blk_size;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < blk_size; y++) {
    if (y > 0) {
        for (x = 0; x < blk_size; x++)
            out[x] = 0;
        out += pitch;
    }
}
}
