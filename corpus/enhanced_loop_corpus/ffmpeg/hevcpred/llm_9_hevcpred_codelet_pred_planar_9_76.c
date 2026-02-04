#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int trafo_size;
extern int x;
extern int y;
extern uint16_t *src;
extern  uint16_t *top;
extern  uint16_t *left;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified arithmetic and reduced effective trip count
    // Outer loop runs only half the iterations, inner loop uses larger step size
    int limit = (size + 1) / 2;  // Reduce trip count
    for (y = 0; y < limit; y++) {
        for (x = 0; x < limit; x++) {
            int idx = x + stride * y;
            // Simplified expression: remove two cross terms, reduce operations
            int weighted_sum = (size - x) * left[y] + (y + 1) * top[x];
            src[idx] = (weighted_sum + (size >> 1)) >> trafo_size;  // Less bit shifting depth
        }
    }
}
