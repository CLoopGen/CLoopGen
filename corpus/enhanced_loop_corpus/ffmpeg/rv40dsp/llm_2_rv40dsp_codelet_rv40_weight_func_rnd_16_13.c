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
    // Variant 1: Consecutive memory access with loop unrolling and direct index calculation
    for (j = 0; j < 16; j++) {
        int offset = j * stride;
        for (i = 0; i < 16; i += 4) {
            // Unroll loop by factor of 4 for consecutive accesses
            dst[offset + i + 0] = ((((unsigned int)w2 * src1[offset + i + 0]) >> 9) + 
                                   (((unsigned int)w1 * src2[offset + i + 0]) >> 9) + 16) >> 5;
            dst[offset + i + 1] = ((((unsigned int)w2 * src1[offset + i + 1]) >> 9) + 
                                   (((unsigned int)w1 * src2[offset + i + 1]) >> 9) + 16) >> 5;
            dst[offset + i + 2] = ((((unsigned int)w2 * src1[offset + i + 2]) >> 9) + 
                                   (((unsigned int)w1 * src2[offset + i + 2]) >> 9) + 16) >> 5;
            dst[offset + i + 3] = ((((unsigned int)w2 * src1[offset + i + 3]) >> 9) + 
                                   (((unsigned int)w1 * src2[offset + i + 3]) >> 9) + 16) >> 5;
        }
    }
}
