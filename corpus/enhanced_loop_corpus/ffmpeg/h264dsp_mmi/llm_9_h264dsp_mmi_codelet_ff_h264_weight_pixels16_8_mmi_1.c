#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *block;
extern ptrdiff_t stride;
extern int height;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (y = 0; y < height; y++, block += stride, step++) {
        // Increase arithmetic complexity within the loop body
        ptrdiff_t offset = (step % 3) ? stride : stride * 2;
        volatile uint8_t val = block[offset];
        val ^= (uint8_t)(y * 37);
    }
}
