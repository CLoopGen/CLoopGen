#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int height;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height; y += 2, dst += stride * 2, src += stride * 2) {
        // Process two rows per iteration to reduce trip count and increase per-iteration work
        uint8_t temp1 = src[0];
        uint8_t temp2 = src[stride];
        dst[0] = temp1 + 1;
        dst[stride] = temp2 + 2;
    }
    // Handle remaining row if height is odd
    if (y == height - 1) {
        dst[0] = src[0] + 1;
    }
}
