#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *row;
extern uint32_t pixels;
extern  uint16_t *gamma_lut;
extern uint32_t i;
extern unsigned char *px;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t j;
    for (j = 0; j < pixels * 4; j += 4) {
        unsigned char *px_base = row + j;
        px_base[0] = gamma_lut[px_base[0]];
        px_base[1] = gamma_lut[px_base[1]];
        px_base[2] = gamma_lut[px_base[2]];
    }
}
