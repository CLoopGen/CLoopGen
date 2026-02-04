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
for (i = 0; i < 4; i++) {
    int offset = i * stride;
    int s0 = src[offset + 0 * stride] + src[offset + 6 * stride];
    int s1 = src[offset + 1 * stride] + src[offset + 5 * stride];
    int s2 = src[offset + 2 * stride] + src[offset + 4 * stride];
    int s3 = src[offset + 3 * stride];
    int s = s3 + s3;
    s3 = s - s0;
    s0 = s + s0;
    s = s2 + s1;
    s2 = s2 - s1;
    dst[0] = s0 + s;
    dst[2] = s0 - s;
    dst[1] = 2 * s3 + s2;
    dst[3] = s3 - 2 * s2;
    dst += 4;
}
}
