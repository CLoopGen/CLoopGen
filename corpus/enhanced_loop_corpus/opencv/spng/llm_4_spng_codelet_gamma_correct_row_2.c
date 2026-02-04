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
    for (i = 0; i < pixels; i++) {
        px = row + i * 4;
        if (px[0] < 128) {
            px[0] = gamma_lut[px[0]];
        }
        if (px[1] < 192) {
            px[1] = gamma_lut[px[1]];
        }
        if (px[2] != 0) {
            px[2] = gamma_lut[px[2]];
        }
    }
}
