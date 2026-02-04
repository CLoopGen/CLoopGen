#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int b_h;
extern int y;
extern  unsigned int color4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride between writes (simulating sparse update)
    // Instead of two adjacent 32-bit writes, we space them further apart
    const int offset1 = 0;
    const int offset2 = 16; // Increased gap to simulate strided pattern
    for (y = 0; y < b_h; y++) {
        *(uint32_t *)&dst[offset1 + y * stride] = color4;
        *(uint32_t *)&dst[offset2 + y * stride] = color4;
    }
}
