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
    // Reduced arithmetic and memory operations by unrolling less and using a nested loop with smaller width
    const int step = 8; // Process 8 bytes at a time instead of 4, assuming alignment allows uint64_t access
    for (y = 0; y < b_h; y++) {
        for (int x = 0; x < 32; x += 8) {
            *(uint64_t *)&dst[x + y * stride] = (uint64_t)color4 | ((uint64_t)color4 << 32);
        }
    }
}
