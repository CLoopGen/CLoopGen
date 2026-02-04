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
    for (i = 0; i < pixels * 3; i++) {
        uint32_t pixel_idx = i / 3;
        uint32_t channel = i % 3;
        px = row + pixel_idx * 4;
        px[channel] = gamma_lut[px[channel]];
    }
}
