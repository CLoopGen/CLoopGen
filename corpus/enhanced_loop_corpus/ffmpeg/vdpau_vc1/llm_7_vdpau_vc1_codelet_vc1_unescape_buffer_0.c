#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev1 = 0, prev2 = 0;
    uint8_t current;
    for (i = 0; i < size; i++) {
        current = src[i];
        // Introduce loop-carried dependency via prev1/prev2 update
        if (current == 3 && i >= 2 && prev1 == 0 && prev2 == 0 && i < size - 1 && src[i+1] < 4) {
            dst[dsize++] = src[i+1];
            prev2 = prev1;
            prev1 = src[i+1]; // WAW-like update creates artificial dependency
            i++; // Skip next input
        } else {
            dst[dsize++] = current;
            prev2 = prev1;
            prev1 = current;
        }
    }
}
