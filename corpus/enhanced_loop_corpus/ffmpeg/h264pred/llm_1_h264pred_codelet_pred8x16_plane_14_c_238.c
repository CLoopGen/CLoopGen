#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int stride;
extern  uint16_t *src1;
extern  uint16_t *src2;
extern int V;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 4; outer <= 8; outer += 4) {
        for (; k <= outer; ++k) {
            src1 += stride;
            src2 -= stride;
            V += k * (src1[0] - src2[0]);
        }
    }
}
