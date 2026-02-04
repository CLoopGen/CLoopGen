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
for (k = 2; k <= 4; ++k) {
    src1 += stride;
    src2 -= stride;
    if (src0[k] > src0[-k]) {
        H += k * (src0[k] - src0[-k]);
    }
    if (src1[0] >= src2[0]) {
        V += k * (src1[0] - src2[0]);
    }
}
}
