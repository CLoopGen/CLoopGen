#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int stride;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int V;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; k <= 16; ++k) {
        src1 += stride;
        src2 -= stride;
        int diff1 = src1[0] - src2[0];
        int diff2 = src1[1] - src2[-1];
        V += k * (diff1 + diff2);
    }
}
