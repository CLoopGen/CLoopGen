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
    for (uint32_t j = 0; j < pixels; j++) {
        unsigned char *px = row + j * 4;
        for (int k = 0; k < 3; k++) {
            px[k] = gamma_lut[px[k]];
        }
    }
}
