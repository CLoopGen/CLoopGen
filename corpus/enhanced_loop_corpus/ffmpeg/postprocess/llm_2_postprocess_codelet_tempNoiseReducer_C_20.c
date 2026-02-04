#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern uint8_t *tempBlurred;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive (linear) memory access by precomputing base pointers and using linear indexing
    uint8_t *tempBase = tempBlurred;
    uint8_t *srcBase = src;
    for (y = 0; y < 8; y++) {
        int offset = y * stride;
        int x;
        for (x = 0; x < 8; x++) {
            int idx = offset + x;
            int ref = tempBase[idx];
            int cur = srcBase[idx];
            tempBase[idx] = srcBase[idx] = (ref + cur + 1) >> 1;
        }
    }
}
