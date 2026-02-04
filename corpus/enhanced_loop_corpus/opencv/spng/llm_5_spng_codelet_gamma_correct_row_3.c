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
        px = row + i * 3;
        uint8_t r = px[0], g = px[1], b = px[2];
        px[0] = (r == 0 || r == 255) ? r : gamma_lut[r];
        px[1] = (g == 0 || g == 255) ? g : gamma_lut[g];
        px[2] = (b == 0 || b == 255) ? b : gamma_lut[b];
    }
}
