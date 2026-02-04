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
for (j = 0; j < 16; j++) {
    for (i = 0; i < 4; i++) {
        uint8_t temp1 = (src1[i] + src2[i]) >> 1;
        uint8_t temp2 = (src1[i + 8] + src2[i + 8]) >> 1;
        dst[i] = ((unsigned int)w2 * temp1 + (unsigned int)w1 * temp2 + 16) >> 6;
    }
    src1 += stride;
    src2 += stride;
    dst += stride;
}
}
