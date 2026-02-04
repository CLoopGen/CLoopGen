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
        uint8_t acc = 0;
        for (i = 0; i < 8; i++) {
            uint8_t val = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
            dst[i] = val;
            acc += val;
        }
        dst[0] += acc >> 3; // Introduce WAW and WAR dependency on dst[0], creates loop-carried dependency via accumulation effect
        src1 += stride;
        src2 += stride;
        dst += stride;
    }
}
