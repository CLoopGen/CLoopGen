#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint8_t *src;
extern int angle;
extern  uint8_t *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Array Reordering
    // Instead of accessing 'ref' with strided offsets, we precompute a temporary array
    // to enable more sequential access patterns in the inner loop.
    uint8_t temp[2 * size]; // Temporary buffer to hold frequently accessed ref data
    for (int i = 0; i < 2 * size; i++) {
        temp[i] = ref[i + 1];
    }

    for (x = 0; x < size; x++) {
        int idx = ((x + 1) * angle) >> 5;
        int fact = ((x + 1) * angle) & 31;

        if (fact) {
            for (y = 0; y < size; y++) {
                src[x + stride * y] = ((32 - fact) * temp[idx + y] + fact * temp[idx + y + 1] + 16) >> 5;
            }
        } else {
            for (y = 0; y < size; y++) {
                src[x + stride * y] = temp[idx + y];
            }
        }
    }
}
