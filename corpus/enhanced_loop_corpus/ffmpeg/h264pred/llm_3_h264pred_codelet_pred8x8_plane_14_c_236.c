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
    // Variant 2: Strided access with fixed base pointers and scaled index arithmetic
    int base_offset;
    for (k = 2; k <= 4; ++k) {
        base_offset = k * stride;  // Introduce strided index scaling based on loop variable
        H += k * (src0[k] - src0[-k]);
        V += k * (src1[base_offset] - src2[-base_offset]);
    }
    // Maintain pointer side effects observed in original loop
    src1 += 3 * stride;
    src2 -= 3 * stride;
}
