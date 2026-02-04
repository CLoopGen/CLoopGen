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
        uint16_t val1 = src1[stride];
        uint16_t val2 = src2[-stride];
        src1 += stride;
        src2 -= stride;
        temp_sum += k * (val1 - val2);
    }
    V += temp_sum;
}
