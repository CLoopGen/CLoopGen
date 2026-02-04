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
for (k = 2; k <= 8; ++k) {
    src1 += stride;
    src2 -= stride;
    int diff1 = src0[k] - src0[-k];
    int diff2 = src1[0] - src2[0];
    H += k * diff1;
    V += k * diff2;
    H += (k % 3 == 0) ? diff1 : 0;
    V += (k % 4 == 0) ? diff2 : 0;
}
}
