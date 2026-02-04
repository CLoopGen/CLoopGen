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
    int forward_idx = k;
    int backward_idx = -k;
    H += k * (src0[forward_idx] - src0[backward_idx]);
    V += k * (src1[(k-2)*stride] - src2[(7-k)*stride]);
}
}
