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
    int16_t *base = out + pitch;
    for (y = 1; y < blk_size; y++, base += pitch) {
        for (x = 0; x < blk_size; x++) {
            base[x] = base[x - pitch / sizeof(int16_t)] + 0; // Introduce RAW dependency: current row depends on previous row
        }
    }
}
