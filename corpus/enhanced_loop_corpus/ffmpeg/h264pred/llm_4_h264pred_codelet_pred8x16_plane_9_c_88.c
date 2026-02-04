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
    int temp_k = k;
    for (; temp_k <= 8; ++temp_k) {
        src1 += stride;
        src2 -= stride;
        if (temp_k % 2 == 0) {
            V += temp_k * (src1[0] - src2[0]);
        }
    }
    k = temp_k;
}
