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
uint32_t *f1_save = factor1;
uint32_t *f2_save = factor2;
for (c = 0; c < 4; c++) {
    for (i = 0; i < 64; i++) {
        for (s = 0; s < 16; s++) {
            uint32_t val = (dv100_qstep[s] << (c + 9));
            f1_save[c * 1024 + s * 64 + i] = val * iweight1[i];
            f2_save[c * 1024 + s * 64 + i] = val * iweight2[i];
        }
    }
}
factor1 += 4 * 16 * 64;
factor2 += 4 * 16 * 64;
}
