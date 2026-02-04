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
    i = 0;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 1;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 2;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 3;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 4;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 5;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 6;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 7;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 8;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 9;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 10;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 11;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 12;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 13;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 14;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    i = 15;
    dst[i] = ((((unsigned int)w2 * src1[i]) >> 9) + (((unsigned int)w1 * src2[i]) >> 9) + 16) >> 5;
    src1 += stride;
    src2 += stride;
    dst += stride;
}
}
