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
    int prev_k = 2;
    int temp_V = V;
    for (k = 2; k <= 4; ++k) {
        src1 += stride;
        src2 -= stride;
        int diff = src0[k] - src0[-k];
        H += k * diff;
        temp_V += k * (src1[0] - src2[0]) + prev_k; // Introduce WAW and RAW: temp_V depends on previous k
        prev_k = k;
    }
    V = temp_V;
}
