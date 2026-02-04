#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int offset = stride * i;
    uint8_t s0 = src[offset + 0], s1 = src[offset + 1];
    uint8_t s2 = src[offset + 2], s3 = src[offset + 3];
    uint8_t s4 = src[offset + 4], s5 = src[offset + 5];
    uint8_t s6 = src[offset + 6], s7 = src[offset + 7];

    temp[8*i+0] = s0 + s1;
    temp[8*i+1] = s0 - s1;
    temp[8*i+2] = s2 + s3;
    temp[8*i+3] = s2 - s3;
    temp[8*i+4] = s4 + s5;
    temp[8*i+5] = s4 - s5;
    temp[8*i+6] = s6 + s7;
    temp[8*i+7] = s6 - s7;

    int t0 = temp[8*i+0], t2 = temp[8*i+2];
    temp[8*i+0] = t0 + t2;
    temp[8*i+2] = t0 - t2;

    int t1 = temp[8*i+1], t3 = temp[8*i+3];
    temp[8*i+1] = t1 + t3;
    temp[8*i+3] = t1 - t3;

    int t4 = temp[8*i+4], t6 = temp[8*i+6];
    temp[8*i+4] = t4 + t6;
    temp[8*i+6] = t4 - t6;

    int t5 = temp[8*i+5], t7 = temp[8*i+7];
    temp[8*i+5] = t5 + t7;
    temp[8*i+7] = t5 - t7;

    int u0 = temp[8*i+0], u4 = temp[8*i+4];
    temp[8*i+0] = u0 + u4;
    temp[8*i+4] = u0 - u4;

    int u1 = temp[8*i+1], u5 = temp[8*i+5];
    temp[8*i+1] = u1 + u5;
    temp[8*i+5] = u1 - u5;

    int u2 = temp[8*i+2], u6 = temp[8*i+6];
    temp[8*i+2] = u2 + u6;
    temp[8*i+6] = u2 - u6;

    int u3 = temp[8*i+3], u7 = temp[8*i+7];
    temp[8*i+3] = u3 + u7;
    temp[8*i+7] = u3 - u7;
}
}
