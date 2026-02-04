#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int stride;
extern  uint16_t * src0;
extern  uint16_t *src1;
extern  uint16_t *src2;
extern int H;
extern int V;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *temp_src1 = src1 + stride;
    uint16_t *temp_src2 = src2 - stride;
    int local_H = H;
    int local_V = V;
    for (k = 2; k <= 4; ++k) {
        local_H += k * (src0[k] - src0[-k]);
        local_V += k * (temp_src1[0] - temp_src2[0]);
        temp_src1 += stride;
        temp_src2 -= stride;
    }
    H = local_H;
    V = local_V;
    src1 = temp_src1 - stride;
    src2 = temp_src2 + stride;
}
