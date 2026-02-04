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
    t1 = 17 * (src[0] + src[2]) + 4;
    t2 = 17 * (src[0] - src[2]) + 4;
    t3 = 22 * src[1] + 10 * src[3];
    t4 = 22 * src[3] - 10 * src[1];
    dst[0] = (t1 + t3) >> 3;
    dst[1] = (t2 - t4) >> 3;
    dst[2] = (t2 + t4) >> 3;
    dst[3] = (t1 - t3) >> 3;
    t1 = 17 * (src[4] + src[6]) + 4;
    t2 = 17 * (src[4] - src[6]) + 4;
    t3 = 22 * src[5] + 10 * src[7];
    t4 = 22 * src[7] - 10 * src[5];
    dst[4] = (t1 + t3) >> 3;
    dst[5] = (t2 - t4) >> 3;
    dst[6] = (t2 + t4) >> 3;
    dst[7] = (t1 - t3) >> 3;
    src += 16;
    dst += 16;
}
}
