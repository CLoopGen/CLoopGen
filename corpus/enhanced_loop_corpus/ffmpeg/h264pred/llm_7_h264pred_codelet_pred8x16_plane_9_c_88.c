#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int stride;
extern  uint16_t *src1;
extern  uint16_t *src2;
extern int V;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *local_src1 = src1;
    uint16_t *local_src2 = src2;
    int local_k = k;
    int local_V = V;

    for (; local_k <= 8; ++local_k) {
        local_src1 += stride;
        local_src2 -= stride;
        local_V += local_k * (local_src1[0] - local_src2[0]);
    }

    src1 = local_src1;
    src2 = local_src2;
    k = local_k;
    V = local_V;
}
