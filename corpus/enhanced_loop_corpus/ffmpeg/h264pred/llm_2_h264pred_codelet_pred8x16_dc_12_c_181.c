#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern int dc3;
extern int dc4;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Reorganize accesses to use consecutive indices where possible by precomputing base pointers
    uint16_t *base0 = src - 1;
    uint16_t *base1 = src - stride;
    uint16_t *base2 = src + 4 - stride;
    uint16_t *base3 = src - 1 + 4 * stride;
    uint16_t *base4 = src - 1 + 8 * stride;
    uint16_t *base5 = src - 1 + 12 * stride;

    for (i = 0; i < 4; i++) {
        dc0 += base0[i * stride] + base1[i];
        dc1 += base2[i];
        dc2 += base3[i * stride];
        dc3 += base4[i * stride];
        dc4 += base5[i * stride];
    }
}
