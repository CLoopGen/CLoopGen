#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t offset = i * stride;
    uint16_t s0 = src[offset];
    uint16_t s1 = src[offset + 1];
    uint16_t s2 = src[offset + 2];
    uint16_t s3 = src[offset + 3];
    uint16_t s_step0 = src[offset + step];
    uint16_t s_step1 = src[offset + step + 1];
    uint16_t s_step2 = src[offset + step + 2];
    uint16_t s_step3 = src[offset + step + 3];

    uint16_t val0 = ((A * s0 + E * s_step0) + 32) >> 6;
    uint16_t val1 = ((A * s1 + E * s_step1) + 32) >> 6;
    uint16_t val2 = ((A * s2 + E * s_step2) + 32) >> 6;
    uint16_t val3 = ((A * s3 + E * s_step3) + 32) >> 6;

    dst[offset] = (dst[offset] + val0 + 1) >> 1;
    dst[offset + 1] = (dst[offset + 1] + val1 + 1) >> 1;
    dst[offset + 2] = (dst[offset + 2] + val2 + 1) >> 1;
    dst[offset + 3] = (dst[offset + 3] + val3 + 1) >> 1;
}
}
