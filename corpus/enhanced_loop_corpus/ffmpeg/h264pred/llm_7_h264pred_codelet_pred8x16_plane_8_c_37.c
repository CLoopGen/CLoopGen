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
    int accumulated_H = H;
    int accumulated_V = V;
    uint8_t* current_src1 = src1;
    uint8_t* current_src2 = src2;
    for (local_k = 2; local_k <= 4; ++local_k) {
        current_src1 += stride;
        current_src2 -= stride;
        accumulated_H += local_k * (src0[local_k] - src0[-local_k]);
        accumulated_V += local_k * (current_src1[0] - current_src2[0]);
    }
    H = accumulated_H;
    V = accumulated_V;
    src1 = current_src1;
    src2 = current_src2;
    k = local_k - 1;
}
