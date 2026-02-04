#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int c;
extern int s;
extern uint32_t *factor1;
extern uint32_t *factor2;
extern  uint8_t dv100_qstep[16];
extern  uint16_t *iweight1;
extern  uint16_t *iweight2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (c = 0; c < 4; c++) {
    for (s = 0; s < 16; s++) {
        uint32_t shift_val = dv100_qstep[s] << (c + 9);
        for (i = 0; i < 64; i++) {
            *factor1++ = shift_val * iweight1[i];
            *factor2++ = shift_val * iweight2[i];
        }
    }
}
}
