#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int16_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int idx = i * 4;
    int s0 = src[idx + 0] + src[idx + 6*4];
    int s1 = src[idx + 1*4] + src[idx + 5*4];
    int s2 = src[idx + 2*4] + src[idx + 4*4];
    int s3 = src[idx + 3*4];
    int s = s3 + s3;
    s3 = s - s0;
    s0 = s + s0;
    s = s2 + s1;
    s2 = s2 - s1;
    dst[idx + 0] = s0 + s;
    dst[idx + 2*4] = s0 - s;
    dst[idx + 1*4] = 2 * s3 + s2;
    dst[idx + 3*4] = s3 - 2 * s2;
}
}
