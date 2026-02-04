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
    int prev_k = 1;
    for (k = 2; k <= 4; ++k) {
        src1 += stride;
        src2 -= stride;
        int diff_k = k - prev_k;
        prev_k = k;
        if (diff_k > 0) {
            H += diff_k * (src0[k] - src0[-k]);
            V += diff_k * (src1[0] - src2[0]);
        }
    }
}
