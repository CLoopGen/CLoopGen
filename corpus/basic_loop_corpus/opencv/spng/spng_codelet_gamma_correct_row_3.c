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
    px[0] = gamma_lut[px[0]];
    px[1] = gamma_lut[px[1]];
    px[2] = gamma_lut[px[2]];
}

}
