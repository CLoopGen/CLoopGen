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
    int local_k;
    int accum_H = H;
    int accum_V = V;
    uint8_t *local_src1 = src1;
    uint8_t *local_src2 = src2;
    for (local_k = 2; local_k <= 8; ++local_k) {
        local_src1 += stride;
        local_src2 -= stride;
        int diff_center = src0[local_k] - src0[-local_k];
        int diff_edges = local_src1[0] - local_src2[0];
        accum_H += local_k * diff_center;
        accum_V += local_k * diff_edges;
    }
    H = accum_H;
    V = accum_V;
    src1 = local_src1;
    src2 = local_src2;
}
