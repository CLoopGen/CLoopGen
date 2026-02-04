#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src1;
extern uint8_t *src2;
extern int w1;
extern int w2;
extern ptrdiff_t stride;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array indexing (flattened iteration)
    int idx = 0;
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            int offset = j * stride + i;
            dst[offset] = ((unsigned int)w2 * src1[offset] + (unsigned int)w1 * src2[offset] + 16) >> 5;
        }
    }
}
