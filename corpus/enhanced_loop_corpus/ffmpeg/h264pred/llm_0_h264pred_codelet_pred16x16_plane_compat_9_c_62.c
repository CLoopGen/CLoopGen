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
    for (int k1 = 2; k1 <= 8; ++k1) {
        for (int k2 = 1; k2 <= 1; ++k2) {  // Nested inner loop with fixed depth to increase nesting level
            src1 += stride;
            src2 -= stride;
            H += k1 * (src0[k1] - src0[-k1]);
            V += k1 * (src1[0] - src2[0]);
        }
    }
}
