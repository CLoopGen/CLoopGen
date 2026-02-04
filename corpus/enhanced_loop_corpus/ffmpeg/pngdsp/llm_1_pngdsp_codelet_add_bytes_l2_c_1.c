#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src1;
extern uint8_t *src2;
extern int w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer;
    const int unroll_factor = 4;
    long remainder = w % unroll_factor;
    long limit = w - remainder;

    for (outer = i; outer < limit; outer += unroll_factor) {
        dst[outer]     = src1[outer]     + src2[outer];
        dst[outer + 1] = src1[outer + 1] + src2[outer + 1];
        dst[outer + 2] = src1[outer + 2] + src2[outer + 2];
        dst[outer + 3] = src1[outer + 3] + src2[outer + 3];
    }
    for (; i < w; i++)
        dst[i] = src1[i] + src2[i];
}
