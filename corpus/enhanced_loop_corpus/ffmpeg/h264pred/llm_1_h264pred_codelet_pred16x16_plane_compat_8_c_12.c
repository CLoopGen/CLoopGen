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
for (k = 2; k <= 4; ++k) {
    for (int extra = 2; extra <= 8; extra += 6) {
        int adjusted_k = extra + (k - 2);
        if (adjusted_k <= 8) {
            uint8_t* temp_src1 = src1 + (adjusted_k - k) * stride;
            uint8_t* temp_src2 = src2 - (adjusted_k - k) * stride;
            H += adjusted_k * (src0[adjusted_k] - src0[-adjusted_k]);
            V += adjusted_k * (temp_src1[0] - temp_src2[0]);
        }
    }
    src1 += stride;
    src2 -= stride;
}
}
