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
for (k = 2; k <= 4; ++k) {
    int idx_load = k;
    int idx_store = -k;
    H += k * (src0[idx_load] - src0[idx_store]);
    V += k * (src1[stride] - src2[-stride]);
    src1 += stride;
    src2 -= stride;
}
}
