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
for (y = 0; y < blk_size / 2; out += pitch * 2, y++) {
    for (x = 0; x < blk_size; x += 2) {
        out[x] = 0;
        if (x + 1 < blk_size)
            out[x + 1] = 0;
    }
}
}
