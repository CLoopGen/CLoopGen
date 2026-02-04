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
for (k = 2; k <= 8; ++k) {
    int idx = k;
    H += k * (src0[idx] - src0[-idx]);
    V += k * (src1[(k-2)*stride] - src2[(k-2)*stride]);
}
src1 += 7 * stride;
src2 -= 7 * stride;
}
