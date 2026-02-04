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
for (k = 1; k <= 6; ++k) {
    src1 += stride;
    src2 -= stride;
    H += k * (src0[k] - src0[-k]);
    V += k * (src1[0] - src2[0]);
    H -= (k-1) * (src0[k-1] - src0[1-k]);
    V -= (k-1) * (src1[-stride] - src2[stride]);
}
}
