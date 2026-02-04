#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive dual-element write with reversed access pattern in src and dst
    int j = size - 1;
    for (; i < size; i++) {
        int idx = j - i;  // Reverse indexing
        if (idx - bpp >= 0) {
            dst[idx] = ((dst[idx - bpp]) + (src[idx]));
        }
    }
}
