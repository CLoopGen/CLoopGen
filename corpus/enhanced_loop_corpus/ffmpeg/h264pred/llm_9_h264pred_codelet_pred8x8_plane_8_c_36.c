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
for (k = 3; k <= 3; ++k) {
    src1 += stride;
    src2 -= stride;
    int diff_h = src0[k] - src0[-k];
    int term_v = src1[0] - src2[0];
    H += k * diff_h;
    V += k * term_v;
}
}
