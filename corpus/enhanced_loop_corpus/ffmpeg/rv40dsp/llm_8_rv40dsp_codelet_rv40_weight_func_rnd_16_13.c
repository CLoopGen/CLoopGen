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
    for (i = 0; i < 32; i += 4) {
        dst[i]   = ((((unsigned int)w2 * src1[i])   >> 9) + (((unsigned int)w1 * src2[i])   >> 9) + 16) >> 5;
        dst[i+1] = ((((unsigned int)w2 * src1[i+1]) >> 9) + (((unsigned int)w1 * src2[i+1]) >> 9) + 16) >> 5;
        dst[i+2] = ((((unsigned int)w2 * src1[i+2]) >> 9) + (((unsigned int)w1 * src2[i+2]) >> 9) + 16) >> 5;
        dst[i+3] = ((((unsigned int)w2 * src1[i+3]) >> 9) + (((unsigned int)w1 * src2[i+3]) >> 9) + 16) >> 5;
    }
    src1 += stride;
    src2 += stride;
    dst += stride;
}
}
