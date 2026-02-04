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
for (; k <= 8; ++k) {
    uint16_t *addr1 = src1 + stride;
    uint16_t *addr2 = src2 - stride;
    src1 = addr1;
    src2 = addr2;
    V += k * (src1[0] - src2[0]);
}
}
