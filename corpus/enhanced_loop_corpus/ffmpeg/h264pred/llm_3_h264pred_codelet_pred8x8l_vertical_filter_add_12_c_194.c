#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *src;
extern  int32_t *block;
extern uint16_t pix[8];
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    uint16_t v = pix[i];
    int base_idx = i;
    uint16_t *src_ptr = &src[base_idx];
    int32_t *block_ptr = &block[base_idx];
    src_ptr[0 * stride] = v += block_ptr[0];
    src_ptr[1 * stride] = v += block_ptr[8];
    src_ptr[2 * stride] = v += block_ptr[16];
    src_ptr[3 * stride] = v += block_ptr[24];
    src_ptr[4 * stride] = v += block_ptr[32];
    src_ptr[5 * stride] = v += block_ptr[40];
    src_ptr[6 * stride] = v += block_ptr[48];
    src_ptr[7 * stride] = v + block_ptr[56];
}
}
