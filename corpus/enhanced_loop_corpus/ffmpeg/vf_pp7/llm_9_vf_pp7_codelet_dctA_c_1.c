#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern uint8_t *src;
extern int stride;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    int s0 = src[0 * stride] + src[6 * stride];
    int s1 = src[1 * stride];
    int s2 = src[2 * stride];
    int s3 = src[3 * stride];
    int t0 = s0 + s1;
    int t1 = s2 + s3;
    dst[0] = t0 + t1;
    dst[1] = t0 - t1;
    dst[2] = s0 - s1;
    dst[3] = s3 - s2;
    src += 2;
    dst += 4;
}
}
