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
uint16_t local_pix[4];
int32_t local_block[16];
for (i = 0; i < 4; i++) {
    local_pix[i] = pix[i];
    local_block[i*4+0] = block[i*4+0];
    local_block[i*4+1] = block[i*4+1];
    local_block[i*4+2] = block[i*4+2];
    local_block[i*4+3] = block[i*4+3];
}
uint16_t v = local_pix[0];
pix[1 * stride] = v + local_block[0];
pix[2 * stride] = v + local_block[0] + local_block[4];
pix[3 * stride] = v + local_block[0] + local_block[4] + local_block[8];
pix[4 * stride] = v + local_block[0] + local_block[4] + local_block[8] + local_block[12];
pix += 4;
block += 16;
}
