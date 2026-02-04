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
for (k = 4; k <= 6; k += 2) {
    src1 += stride;
    src2 -= stride;
    int idx1 = k / 2;
    int idx2 = k * 2;
    H += idx1 * (src0[idx1] - src0[-idx1]);
    V += idx1 * (src1[0] - src2[0]);
    H += idx1 * (src0[idx2] - src0[-idx2]);
}
}
