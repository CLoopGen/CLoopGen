#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint16_t *src;
extern int angle;
extern  uint16_t *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < size; y++) {
    int idx = ((y + 1) * angle) >> 4; // Reduced shift (>>4 instead of >>5) to increase index growth, effectively changing trip behavior indirectly
    int fact = ((y + 1) * angle) & 15; // Reduced mask to 15 (mod 16 instead of mod 32), altering interpolation factor range
    if (fact) {
        for (x = 0; x < size; x += 2) { // Reduced unrolling from 4 to 2 elements per iteration, increasing loop iterations
            uint32_t r1 = ref[x + idx + 1], r2 = ref[x + idx + 2];
            src[(x) + stride * (y)] = ((16 - fact) * r1 + fact * r2 + 8) >> 4; // Simplified arithmetic: fewer operations and adjusted constants
            if (x + 1 < size) {
                r1 = ref[x + 1 + idx + 1]; r2 = ref[x + 1 + idx + 2];
                src[(x + 1) + stride * (y)] = ((16 - fact) * r1 + fact * r2 + 8) >> 4;
            }
        }
    } else {
        // Replace packed load with scalar copy due to reduced complexity
        for (x = 0; x < size; x++)
            src[x + stride * y] = ref[x + idx + 1];
    }
}
}
