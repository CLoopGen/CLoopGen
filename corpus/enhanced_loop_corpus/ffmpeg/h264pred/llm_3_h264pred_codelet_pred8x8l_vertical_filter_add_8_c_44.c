#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *src;
extern  int16_t *block;
extern uint8_t pix[8];
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    uint8_t v = pix[i];
    int base_idx = i;
    uint8_t *src_ptr = &src[base_idx];
    int16_t *block_ptr = &block[base_idx];
    src_ptr[0] = v += block_ptr[0];
    src_ptr[stride] = v += block_ptr[8];
    src_ptr[2*stride] = v += block_ptr[16];
    src_ptr[3*stride] = v += block_ptr[24];
    src_ptr[4*stride] = v += block_ptr[32];
    src_ptr[5*stride] = v += block_ptr[40];
    src_ptr[6*stride] = v += block_ptr[48];
    src_ptr[7*stride] = v + block_ptr[56];
    src++;
    block++;
}
}
