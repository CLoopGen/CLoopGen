#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *output;
extern int p1;
extern int i;
extern uint16_t pix16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < p1; j++) {
        output[2*j]     = (uint8_t)(pix16 & 0xFF);
        output[2*j + 1] = (uint8_t)((pix16 >> 8) & 0xFF);
    }
}
