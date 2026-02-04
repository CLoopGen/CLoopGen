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
for (k = 2; k <= 4; ++k) {
    int idx = k;
    uint8_t val1 = *(src0 + idx);
    uint8_t val2 = *(src0 - idx);
    src1 += stride;
    src2 -= stride;
    uint8_t val3 = src1[0];
    uint8_t val4 = src2[0];
    H += k * (val1 - val2);
    V += k * (val3 - val4);
}
}
