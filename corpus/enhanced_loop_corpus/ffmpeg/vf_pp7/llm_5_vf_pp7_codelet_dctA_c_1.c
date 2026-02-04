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
    int s0, s1, s2, s3, s;
    if (src[3 * stride] > 127) {
        s0 = src[0 * stride] + src[6 * stride];
        s1 = src[1 * stride] + src[5 * stride];
        s2 = src[2 * stride] + src[4 * stride];
        s3 = src[3 * stride];
        s = s3 + s3;
        s3 = s - s0;
        s0 = s + s0;
        s = s2 + s1;
        s2 = s2 - s1;
        dst[0] = (s0 + s) >> 1;
        dst[2] = (s0 - s) >> 1;
        dst[1] = (2 * s3 + s2) >> 1;
        dst[3] = (s3 - 2 * s2) >> 1;
    } else {
        s0 = src[0 * stride] - src[6 * stride];
        s1 = src[1 * stride] - src[5 * stride];
        s2 = src[2 * stride] - src[4 * stride];
        s3 = src[3 * stride];
        s = s3;
        dst[0] = s0 + s1 + s2 + s3;
        dst[1] = s0 - s1;
        dst[2] = s2 - s3;
        dst[3] = s0 + s2;
    }
    src++;
    dst += 4;
}
}
