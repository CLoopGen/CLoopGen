#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int stride;
extern  uint8_t * src0;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int H;
extern int V;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_H = H;
    int temp_V = V;
    uint8_t *s1 = src1 + stride;
    uint8_t *s2 = src2 - stride;
    for (k = 2; k <= 8; ++k) {
        temp_H += k * (src0[k] - src0[-k]);
        temp_V += k * (s1[0] - s2[0]);
        s1 += stride;
        s2 -= stride;
    }
    H = temp_H;
    V = temp_V;
    src1 = s1;
    src2 = s2;
}
