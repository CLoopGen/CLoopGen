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
    // Variant 2: Reduced loop depth by unrolling the loop when b_h is small and known
    // Assuming b_h is at most 4 for unrolling (safe handling for any b_h via conditionals)
    y = 0;
    if (y < b_h) {
        *(uint32_t *)&dst[0 + y * stride] = color4;
        y++;
    }
    if (y < b_h) {
        *(uint32_t *)&dst[0 + y * stride] = color4;
        y++;
    }
    if (y < b_h) {
        *(uint32_t *)&dst[0 + y * stride] = color4;
        y++;
    }
    if (y < b_h) {
        *(uint32_t *)&dst[0 + y * stride] = color4;
        y++;
    }
    // For larger b_h, fall back to a single loop for remaining iterations
    for (; y < b_h; y++) {
        *(uint32_t *)&dst[0 + y * stride] = color4;
    }
}
