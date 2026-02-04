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
    for (i = 0; i < pixels; i++) {
        px = row + i * 3;
        for (j = 0; j < 3; j++) {
            px[j] = gamma_lut[px[j]];
        }
    }
}
