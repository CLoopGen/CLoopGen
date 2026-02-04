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
    int temp_H = H;
    int temp_V = V;
    uint16_t *local_src1 = src1;
    uint16_t *local_src2 = src2;
    for (k = 2; k <= 4; ++k) {
        local_src1 += stride;
        local_src2 -= stride;
        temp_H += k * (src0[k] - src0[-k]);
        temp_V += k * (local_src1[0] - local_src2[0]);
    }
    H = temp_H;
    V = temp_V;
}
