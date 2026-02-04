#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern uint8_t *pix;
extern  int16_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    uint8_t v = pix[0];
    // Change memory access pattern to consecutive in block and use direct offsetting in pix via precomputed indices
    int base_idx = i * stride;
    pix[base_idx + stride]   = v += block[0];
    pix[base_idx + 2*stride] = v += block[1];
    pix[base_idx + 3*stride] = v += block[2];
    pix[base_idx + 4*stride] = v += block[3];
    pix[base_idx + 5*stride] = v += block[4];
    pix[base_idx + 6*stride] = v += block[5];
    pix[base_idx + 7*stride] = v += block[6];
    pix[base_idx + 8*stride] = v + block[7];
    pix++;
    block += 8; // Step block by 8 now due to consecutive access
}
}
