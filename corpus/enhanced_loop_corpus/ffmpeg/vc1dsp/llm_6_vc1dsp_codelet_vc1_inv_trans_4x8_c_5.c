#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int t1;
extern int t2;
extern int t3;
extern int t4;
extern int16_t *src;
extern int16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int16_t s0 = src[0], s1 = src[1], s2 = src[2], s3 = src[3];
    t1 = 17 * (s0 + s2) + 4;
    t2 = 17 * (s0 - s2) + 4;
    t3 = 22 * s1 + 10 * s3;
    t4 = 22 * s3 - 10 * s1;
    dst[0] = (t1 + t3) >> 3;
    dst[1] = (t2 - t4) >> 3;
    dst[2] = (t2 + t4) >> 3;
    dst[3] = (t1 - t3) >> 3;
    src += 8;
    dst += 8;
}
}
