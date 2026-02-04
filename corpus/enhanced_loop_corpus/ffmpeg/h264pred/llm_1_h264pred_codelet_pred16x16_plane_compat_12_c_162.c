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
    for (int outer_k = 2; outer_k <= 4; ++outer_k) {  // Outer loop splits original range
        for (k = outer_k * 2; k <= (outer_k == 4 ? 8 : outer_k * 2 + 1); ++k) {  // Inner loop handles variable subrange
            src1 += stride;
            src2 -= stride;
            H += k * (src0[k] - src0[-k]);
            V += k * (src1[0] - src2[0]);
        }
    }
}
