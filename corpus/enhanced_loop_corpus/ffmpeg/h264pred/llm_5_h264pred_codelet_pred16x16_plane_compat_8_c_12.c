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
    int coeff = k;
    if (coeff == 3 || coeff == 7) {
        continue;
    }
    H += coeff * (src0[k] - src0[-k]);
    V += coeff * (src1[0] - src2[0]);
}
}
