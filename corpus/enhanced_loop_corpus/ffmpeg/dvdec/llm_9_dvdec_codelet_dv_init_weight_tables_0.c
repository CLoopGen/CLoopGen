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
for (c = 0; c < 2; c++) {
    for (s = 0; s < 8; s++) {
        for (i = 0; i < 32; i++) {
            uint32_t base = dv100_qstep[s] << (c + 9);
            *factor1++ = (base * iweight1[i]) + (base >> 1);
            *factor2++ = (base * iweight2[i]) - (base >> 2);
        }
    }
}
}
