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
    int idx = i * 8;
    t1 = 17 * (src[idx + 0] + src[idx + 2]) + 4;
    t2 = 17 * (src[idx + 0] - src[idx + 2]) + 4;
    t3 = 22 * src[idx + 1] + 10 * src[idx + 3];
    t4 = 22 * src[idx + 3] - 10 * src[idx + 1];
    dst[idx + 0] = (t1 + t3) >> 3;
    dst[idx + 1] = (t2 - t4) >> 3;
    dst[idx + 2] = (t2 + t4) >> 3;
    dst[idx + 3] = (t1 - t3) >> 3;
}
}
