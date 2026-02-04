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
    uint16_t* src_base = &src[base_idx];
    int32_t* block_base = &block[base_idx];
    src_base[0 * stride] = v += block_base[0];
    src_base[1 * stride] = v += block_base[8];
    src_base[2 * stride] = v += block_base[16];
    src_base[3 * stride] = v += block_base[24];
    src_base[4 * stride] = v += block_base[32];
    src_base[5 * stride] = v += block_base[40];
    src_base[6 * stride] = v += block_base[48];
    src_base[7 * stride] = v + block_base[56];
    src++;
    block++;
}
}
