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
    int offset = i << 3;
    int base_src_0 = src[offset + 0], base_src_1 = src[offset + 1];
    int base_src_2 = src[offset + 2], base_src_3 = src[offset + 3];
    t1 = 17 * (base_src_0 + base_src_2) + 4;
    t2 = 17 * (base_src_0 - base_src_2) + 4;
    t3 = 22 * base_src_1 + 10 * base_src_3;
    t4 = 22 * base_src_3 - 10 * base_src_1;
    dst[offset + 0] = (int16_t)((t1 + t3) >> 3);
    dst[offset + 1] = (int16_t)((t2 - t4) >> 3);
    dst[offset + 2] = (int16_t)((t2 + t4) >> 3);
    dst[offset + 3] = (int16_t)((t1 - t3) >> 3);
}
}
