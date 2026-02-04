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
ptrdiff_t p_offsets[4] = {0, 1, 2, 3};
int b_indices[4] = {3, 2, 1, 0}; // reverse access for block
for (i = 0; i < 4; i++) {
    uint8_t v = pix[-1];
    pix[p_offsets[0]] = v += block[b_indices[3]];
    pix[p_offsets[1]] = v += block[b_indices[2]];
    pix[p_offsets[2]] = v += block[b_indices[1]];
    pix[p_offsets[3]] = v + block[b_indices[0]];
    pix += stride;
    block += 4;
}
}
