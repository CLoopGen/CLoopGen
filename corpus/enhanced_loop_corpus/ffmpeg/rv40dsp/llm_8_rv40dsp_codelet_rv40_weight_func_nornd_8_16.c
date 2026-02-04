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
for (j = 0; j < 4; j++) {
    for (i = 0; i < 16; i += 2) {
        unsigned int val1 = (unsigned int)w2 * src1[i];
        unsigned int val2 = (unsigned int)w1 * src2[i];
        unsigned int val3 = (unsigned int)w2 * src1[i+1];
        unsigned int val4 = (unsigned int)w1 * src2[i+1];
        dst[i]   = (val1 + val2 + 16) >> 5;
        dst[i+1] = (val3 + val4 + 16) >> 5;
    }
    src1 += stride;
    src2 += stride;
    dst += stride;
}
}
