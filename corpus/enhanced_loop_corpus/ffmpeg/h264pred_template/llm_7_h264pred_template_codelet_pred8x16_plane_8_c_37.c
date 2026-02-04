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
    int cache[3];
    for (k = 2; k <= 4; ++k) {
        int idx = k - 2;
        cache[idx] = k * (src0[k] - src0[-k]);
        src1 += stride;
        src2 -= stride;
    }
    for (k = 2; k <= 4; ++k) {
        int idx = k - 2;
        H += cache[idx];
        V += k * (src1[stride * (4 - k)] - src2[-stride * (4 - k)]);
    }
}
