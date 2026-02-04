#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int trafo_size;
extern int x;
extern int y;
extern uint8_t *src;
extern  uint8_t *top;
extern  uint8_t *left;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with decreased trip count and simplified arithmetic
    // Loop runs only over half the domain with fewer operations per element
    int half_size = (size + 1) >> 1;  // Effectively ceil(size/2)
    for (y = 0; y < half_size; y++) {
        for (x = 0; x < half_size; x++) {
            int idx = x + stride * y;
            // Simplified weighted sum: remove two terms and reduce bit shift complexity
            int value = ((size - x) * left[y] + (y + 1) * top[x] + (size >> 1)) >> trafo_size;
            src[idx] = (uint8_t)value;
        }
    }
}
