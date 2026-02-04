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
        if (k % 2 == 0) {
            src1 += stride;
        } else {
            src2 -= stride;
        }
        H += k * (src0[k] - src0[-k]);
        V += k * (src1[0] - src2[0]);
    }
}
