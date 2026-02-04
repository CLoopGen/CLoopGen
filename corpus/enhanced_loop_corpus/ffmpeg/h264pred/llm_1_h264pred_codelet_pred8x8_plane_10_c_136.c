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
    for (int k_outer = 2; k_outer <= 4; k_outer += 3) {  // Decreased effective depth via larger step and flattened logic
        for (int k = k_outer; k < k_outer + 3 && k <= 4; ++k) {  // Simulates original k=2,3,4 with outer/inner structure
            src1 += stride;
            src2 -= stride;
            H += k * (src0[k] - src0[-k]);
            V += k * (src1[0] - src2[0]);
        }
    }
}
