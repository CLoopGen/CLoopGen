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
    // Increased computational intensity with inner loop and more arithmetic
    for (y = 0; y < height; y++, dst += stride, src += stride) {
        uint32_t sum = 0;
        int x;
        for (x = 0; x < stride; x++) {
            sum += (uint32_t)(src[x]) * (x + 1);  // Weighted sum of row elements
        }
        dst[0] = (uint8_t)((sum >> 4) & 0xFF);  // Store compressed result
    }
}
