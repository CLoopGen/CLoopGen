#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern uint8_t *dst;
extern int dx;
extern int w;
extern unsigned int asrc;
extern unsigned int tau;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with stride of 2 elements
    // Process every second element first, then the others (interleaved access pattern)
    uint8_t *d = dst;
    int step = 2 * dx;
    int offset;

    // First pass: process even-indexed elements (0, 2, 4, ...)
    for (x = 0; x < w; x += 2) {
        uint16_t value = (((const union unaligned_16 *)(d + x * dx))->l);
        (((union unaligned_16 *)(d + x * dx))->l) = ((value * tau + asrc) >> 16);
    }

    // Second pass: process odd-indexed elements (1, 3, 5, ...)
    for (x = 1; x < w; x += 2) {
        uint16_t value = (((const union unaligned_16 *)(d + x * dx))->l);
        (((union unaligned_16 *)(d + x * dx))->l) = ((value * tau + asrc) >> 16);
    }

    // Final update of global dst after full traversal
    dst = d + w * dx;
}
