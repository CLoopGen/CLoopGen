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
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with flattened index arithmetic and reduced repeated calculations
    // Precompute base pointers and use a single strided traversal
    uint8_t *base_src = src - stride - 1; // Common offset base
    ptrdiff_t s = stride;
    for (i = 0; i < 4; i++) {
        ptrdiff_t idx = i * s;
        dc0 += base_src[idx + s] + base_src[idx + 1];         // src[-1+i*stride] + src[i-stride]
        dc1 += base_src[idx + s + 5];                        // src[4+i-stride]
        dc2 += base_src[idx + 5*s + 1];                      // src[-1+(i+4)*stride]
        dc3 += base_src[idx + 9*s + 1];                      // src[-1+(i+8)*stride]
        dc4 += base_src[idx + 13*s + 1];                     // src[-1+(i+12)*stride]
    }
}
