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
for (j = 0; j < 8; j++) {
    for (i = 0; i < 8; i++) {
        int idx = i * 4; // Strided access with step of 4 elements
        if (idx < 32) { // Bound check to stay within effective range
            dst[idx] = ((((unsigned int)w2 * src1[idx]) >> 9) + (((unsigned int)w1 * src2[idx]) >> 9) + 16) >> 5;
        }
    }
    src1 += stride;
    src2 += stride;
    dst += stride;
}
}
