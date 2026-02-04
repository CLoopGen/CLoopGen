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
for (k = 2; k <= 8; ++k) {
    int idx = k;
    uint16_t *s1_ptr = src1 + stride;
    uint16_t *s2_ptr = src2 - stride;
    H += idx * (src0[idx] - src0[-idx]);
    V += idx * (s1_ptr[0] - s2_ptr[0]);
    src1 = s1_ptr;
    src2 = s2_ptr;
}
}
