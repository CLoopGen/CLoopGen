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
    for (y = 1; y < blk_size; out += pitch, y++) {
        x = 0;
        if (x < blk_size) {
            do {
                out[x] = 0;
                x++;
            } while (x < blk_size);
        }
    }
}
