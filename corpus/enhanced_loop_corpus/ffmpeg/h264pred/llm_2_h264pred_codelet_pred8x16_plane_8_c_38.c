#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int stride;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int V;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; k <= 8; ++k) {
        uint8_t *addr1 = src1 + k * stride;
        uint8_t *addr2 = src2 - k * stride;
        V += k * (addr1[0] - addr2[0]);
        src1 += stride;
        src2 -= stride;
    }
}
