#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *output;
extern int p1;
extern int i;
extern uint8_t pix[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp0, temp1, temp2;
    for (i = 0; i < p1; i++) {
        temp0 = pix[0];
        temp1 = pix[1]; 
        temp2 = pix[2];
        *output++ = temp0;
        *output++ = temp1;
        *output++ = temp2;
    }
}
