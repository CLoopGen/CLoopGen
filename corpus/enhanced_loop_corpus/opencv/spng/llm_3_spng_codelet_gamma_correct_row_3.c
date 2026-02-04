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
    // Interleaved access: process R of all pixels first, then G, then B
    for (j = 0; j < 3; j++) {
        uint32_t k;
        for (k = 0; k < pixels; k++) {
            unsigned char *px = row + k * 3 + j;
            *px = gamma_lut[*px];
        }
    }
}
