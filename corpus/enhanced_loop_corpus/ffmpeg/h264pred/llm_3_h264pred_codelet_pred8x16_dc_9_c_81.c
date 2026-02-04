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
    // Variant 2: Strided access converted to base-offset consecutive indexing with linearized access pattern
    ptrdiff_t s = stride;
    uint16_t *base0 = &src[-1];
    uint16_t *base1 = &src[-s];
    uint16_t *base2 = &src[4 - s];
    for (i = 0; i < 4; i++) {
        dc0 += base0[i * s] + base1[i];
        dc1 += base2[i];
        dc2 += base0[(i + 4) * s];
        dc3 += base0[(i + 8) * s];
        dc4 += base0[(i + 12) * s];
    }
}
