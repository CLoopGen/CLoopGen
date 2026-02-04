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
    int local_k;
    int accumulated_H = H;
    int accumulated_V = V;
    uint16_t *local_src1 = src1;
    uint16_t *local_src2 = src2;
    for (local_k = 2; local_k <= 4; ++local_k) {
        local_src1 += stride;
        local_src2 -= stride;
        int diff0 = src0[local_k] - src0[-local_k];
        int diff1 = local_src1[0] - local_src2[0];
        accumulated_H += local_k * diff0;
        accumulated_V += local_k * diff1;
    }
    H = accumulated_H;
    V = accumulated_V;
}
