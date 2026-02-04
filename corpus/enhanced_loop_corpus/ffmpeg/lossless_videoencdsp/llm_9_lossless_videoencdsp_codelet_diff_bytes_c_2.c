#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern intptr_t w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i + 3 < w; i += 4) {
    uint8_t s1_0 = src1[i + 0], s2_0 = src2[i + 0];
    uint8_t s1_1 = src1[i + 1], s2_1 = src2[i + 1];
    uint8_t s1_2 = src1[i + 2], s2_2 = src2[i + 2];
    uint8_t s1_3 = src1[i + 3], s2_3 = src2[i + 3];

    dst[i + 0] = s1_0 - s2_0;
    dst[i + 1] = s1_1 - s2_1;
    dst[i + 2] = s1_2 - s2_2;
    dst[i + 3] = s1_3 - s2_3;
}
}
