#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern with Increased Stride
    // Modify access pattern to use a larger stride on both src and dst
    // Simulate wider data reuse or cache line oriented access.
    // Process every 16th byte in logical blocks, but still operate on 8-byte output chunks.
    int base;
    for (base = x - 7; base >= 0; base -= 16) {
        int eff_x = base;
        dst[eff_x + 0] = dst[eff_x + 1] = src[(eff_x >> 1) + 0];
        dst[eff_x + 2] = dst[eff_x + 3] = src[(eff_x >> 1) + 1];
        dst[eff_x + 4] = dst[eff_x + 5] = src[(eff_x >> 1) + 2];
        dst[eff_x + 6] = dst[eff_x + 7] = src[(eff_x >> 1) + 3];
        // Skip next 8 indices intentionally to create strided access over iterations
    }
    // Adjust final state of x to reflect progress
    x = base;
}
