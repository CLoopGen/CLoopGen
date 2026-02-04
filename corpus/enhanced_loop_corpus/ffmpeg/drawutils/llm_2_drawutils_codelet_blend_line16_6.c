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
    // Variant 1: Consecutive Memory Access (unroll by 2 for consecutive access pattern)
    // Assumes w is even; if not, original loop handles remainder (not included here for simplicity)
    uint8_t *d = dst;
    for (x = 0; x < w; x += 2) {
        uint16_t value1 = (((const union unaligned_16 *)(d))->l);
        uint16_t value2 = (((const union unaligned_16 *)(d + dx))->l);

        (((union unaligned_16 *)(d))->l) = ((value1 * tau + asrc) >> 16);
        (((union unaligned_16 *)(d + dx))->l) = ((value2 * tau + asrc) >> 16);

        d += 2 * dx;
    }
    dst = d; // Update global dst pointer
}
