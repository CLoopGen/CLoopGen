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
    // Variant 2: Reduced computational intensity with lower trip count and simplified expressions
    for (i = 0; i < 2; i++) {
        dc0 += src[i * stride] + src[i - stride];
        dc1 += src[4 + i - stride];
        // Combine multiple updates into fewer memory accesses
        dc2 += src[(i + 4) * stride];
        dc3 += src[(i + 8) * stride];
        dc4 += src[(i + 12) * stride];
    }
}
