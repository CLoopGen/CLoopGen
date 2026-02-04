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
    int temp_accum_H = 0;
    int temp_accum_V = 0;
    uint8_t *indirect_src1 = src1;
    uint8_t *indirect_src2 = src2;
    for (k = 2; k <= 8; ++k) {
        indirect_src1 += stride;
        indirect_src2 -= stride;
        temp_accum_H += k * (src0[k] - src0[-k]);
        temp_accum_V += k * (indirect_src1[0] - indirect_src2[0]);
    }
    H += temp_accum_H;
    V += temp_accum_V;
}
