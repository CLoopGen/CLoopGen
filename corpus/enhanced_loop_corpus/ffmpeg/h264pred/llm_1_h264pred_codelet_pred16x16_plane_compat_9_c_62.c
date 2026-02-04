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
    // Flattened version by unrolling the loop and reducing depth to zero (no loop)
    int k = 2;
    src1 += stride;
    src2 -= stride;
    H += k * (src0[k] - src0[-k]);
    V += k * (src1[0] - src2[0]);

    k = 3;
    src1 += stride;
    src2 -= stride;
    H += k * (src0[k] - src0[-k]);
    V += k * (src1[0] - src2[0]);

    k = 4;
    src1 += stride;
    src2 -= stride;
    H += k * (src0[k] - src0[-k]);
    V += k * (src1[0] - src2[0]);

    k = 5;
    src1 += stride;
    src2 -= stride;
    H += k * (src0[k] - src0[-k]);
    V += k * (src1[0] - src2[0]);

    k = 6;
    src1 += stride;
    src2 -= stride;
    H += k * (src0[k] - src0[-k]);
    V += k * (src1[0] - src2[0]);

    k = 7;
    src1 += stride;
    src2 -= stride;
    H += k * (src0[k] - src0[-k]);
    V += k * (src1[0] - src2[0]);

    k = 8;
    src1 += stride;
    src2 -= stride;
    H += k * (src0[k] - src0[-k]);
    V += k * (src1[0] - src2[0]);
}
