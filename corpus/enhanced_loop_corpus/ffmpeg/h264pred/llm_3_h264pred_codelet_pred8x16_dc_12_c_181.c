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
    // Variant 2: Strided access with combined accumulation using a single pointer walk
    // Use a strided step through the source array via scaled index arithmetic to enhance spatial predictability
    ptrdiff_t s = stride;
    for (i = 0; i < 4; i++) {
        ptrdiff_t idx0 = -1 + i * s;
        ptrdiff_t idx1 = i - s;
        ptrdiff_t idx2 = 4 + i - s;
        ptrdiff_t idx3 = -1 + (i + 4) * s;
        ptrdiff_t idx4 = -1 + (i + 8) * s;
        ptrdiff_t idx5 = -1 + (i + 12) * s;

        dc0 += src[idx0] + src[idx1];
        dc1 += src[idx2];
        dc2 += src[idx3];
        dc3 += src[idx4];
        dc4 += src[idx5];
    }
}
