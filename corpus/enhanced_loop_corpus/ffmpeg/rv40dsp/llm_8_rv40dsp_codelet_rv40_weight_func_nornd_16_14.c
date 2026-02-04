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
    int j;
    for (j = 0; j < 8; j++) {
        int i;
        for (i = 0; i < 32; i += 2) {
            unsigned int val1_low = (unsigned int)w2 * src1[i] + (unsigned int)w1 * src2[i] + 16;
            unsigned int val1_high = (unsigned int)w2 * src1[i+1] + (unsigned int)w1 * src2[i+1] + 16;
            dst[i] = val1_low >> 5;
            dst[i+1] = val1_high >> 5;
        }
        src1 += stride;
        src2 += stride;
        dst += stride;
    }
}
