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
for (k = 2; k <= 3; ++k) {
    src1 += stride;
    src2 -= stride;
    int temp_h = src0[k] - src0[-k];
    int temp_v = src1[0] - src2[0];
    H += k * temp_h * temp_h;
    V += k * temp_v * temp_v;
    H -= (k % 2) * (src0[k-1] - src0[1-k]);
}
}
