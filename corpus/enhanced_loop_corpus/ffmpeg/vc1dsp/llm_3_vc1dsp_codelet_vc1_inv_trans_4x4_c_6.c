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
for (i = 0; i < 4; i++) {
    int base_src = i * 2;
    int base_dst = i * 2;
    t1 = 17 * (src[base_src + 0] + src[base_src + 4]) + 4;
    t2 = 17 * (src[base_src + 0] - src[base_src + 4]) + 4;
    t3 = 22 * src[base_src + 1] + 10 * src[base_src + 5];
    t4 = 22 * src[base_src + 5] - 10 * src[base_src + 1];
    dst[base_dst + 0] = (t1 + t3) >> 3;
    dst[base_dst + 8] = (t2 - t4) >> 3;
    dst[base_dst + 16] = (t2 + t4) >> 3;
    dst[base_dst + 24] = (t1 - t3) >> 3;
}
}
