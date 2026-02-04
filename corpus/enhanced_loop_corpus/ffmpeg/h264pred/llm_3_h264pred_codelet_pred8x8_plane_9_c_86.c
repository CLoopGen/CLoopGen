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
    uint16_t *access_src1 = &src1[stride];
    uint16_t *access_src2 = &src2[-stride];
    src1 = access_src1;
    src2 = access_src2;
    H += k * (src0[k] - src0[-k]);
    V += k * (access_src1[0] - access_src2[0]);
}
}
