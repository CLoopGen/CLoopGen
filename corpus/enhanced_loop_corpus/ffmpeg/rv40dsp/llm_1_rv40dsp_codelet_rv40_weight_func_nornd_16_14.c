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
for (i = 0; i < 256; i++) {
    int j = i / 16;
    int local_i = i % 16;
    dst[local_i] = ((unsigned int)w2 * src1[local_i] + (unsigned int)w1 * src2[local_i] + 16) >> 5;
    if (local_i == 15) {
        src1 += stride;
        src2 += stride;
        dst += stride;
    }
}
}
