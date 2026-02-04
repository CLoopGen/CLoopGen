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
    for (i = 0; i < 8; i++) {
        dst[i] = ((unsigned int)w2 * src1[i] + (unsigned int)w1 * src2[i] + 16) >> 5;
        dst[stride + i] = ((unsigned int)w2 * src1[stride + i] + (unsigned int)w1 * src2[stride + i] + 16) >> 5;
    }
    src1 += 2 * stride;
    src2 += 2 * stride;
    dst += 2 * stride;
}
}
