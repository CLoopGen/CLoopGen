#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern intptr_t w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access from end to beginning
    // Iterates backward through the arrays, maintaining functional equivalence
    for (; i >= 0 && (w - 1 - i) >= 0; i++) {
        intptr_t idx = w - 1 - i;
        dst[idx] = src1[idx] - src2[idx];
    }
}
