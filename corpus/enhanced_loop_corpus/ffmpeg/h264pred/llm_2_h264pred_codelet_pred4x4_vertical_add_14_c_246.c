#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern uint16_t *pix;
extern  int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing pixel and block offsets
    // Access pattern changed to use base pointer arithmetic with consecutive strides
    uint16_t *p_base = pix;
    int32_t *b_base = block;
    for (i = 0; i < 4; i++) {
        ptrdiff_t offset = i * stride;
        uint16_t v = p_base[offset];
        p_base[offset + 1 * stride] = v += b_base[0];
        p_base[offset + 2 * stride] = v += b_base[4];
        p_base[offset + 3 * stride] = v += b_base[8];
        p_base[offset + 4 * stride] = v + b_base[12];
    }
}
