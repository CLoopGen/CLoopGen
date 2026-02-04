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
    int temp_H = H;
    for (k = 2; k <= 8; ++k) {
        uint16_t val1 = src0[k];
        uint16_t val2 = src0[-k];
        src1 += stride;
        src2 -= stride;
        temp_H += k * (val1 - val2);
        V += k * (src1[0] - src2[0]);
    }
    H = temp_H;
}
