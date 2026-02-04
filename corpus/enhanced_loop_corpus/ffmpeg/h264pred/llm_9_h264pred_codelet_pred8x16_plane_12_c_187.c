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
for (k = 2; k <= 3; ++k) {
    src1 += stride;
    src2 -= stride;
    int temp1 = src0[k] - src0[-k];
    int temp2 = src1[0] - src2[0];
    H += k * temp1;
    V += k * temp2;
    if (k == 2) {
        H += (k+1) * (src0[k+1] - src0[-k-1]);
        V += (k+1) * (src1[stride] - src2[-stride]);
    }
}
}
