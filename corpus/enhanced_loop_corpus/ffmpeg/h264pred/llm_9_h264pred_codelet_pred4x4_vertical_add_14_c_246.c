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
for (i = 0; i < 2; i++) {
    uint16_t v1 = pix[0];
    uint16_t v2 = pix[stride];
    
    v1 += block[0]; 
    pix[1 * stride] = v1;
    v1 += block[4]; 
    pix[2 * stride] = v1;
    v1 += block[8]; 
    pix[3 * stride] = v1;
    v1 += block[12]; 
    pix[4 * stride] = v1;

    v2 += block[1]; 
    pix[5 * stride] = v2;
    v2 += block[5]; 
    pix[6 * stride] = v2;
    v2 += block[9]; 
    pix[7 * stride] = v2;
    v2 += block[13]; 
    pix[8 * stride] = v2;

    pix += 2;
    block += 2;
}
}
