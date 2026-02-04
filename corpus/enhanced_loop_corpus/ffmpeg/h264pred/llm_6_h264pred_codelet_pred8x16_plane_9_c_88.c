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
    int temp_sum = 0;
    for (; k <= 8; ++k) {
        src1 += stride;
        src2 -= stride;
        temp_sum += k * (src1[0] - src2[0]);
    }
    V += temp_sum;
}
