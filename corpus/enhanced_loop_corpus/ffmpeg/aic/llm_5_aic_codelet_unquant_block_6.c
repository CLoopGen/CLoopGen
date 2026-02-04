#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int q;
extern uint8_t *quant_matrix;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i++) {
    int val = (uint16_t)block[i];
    int sign = val & 1;
    int magnitude = (val >> 1);
    if (sign) {
        magnitude = -magnitude;
    }
    magnitude = magnitude * q * quant_matrix[i] >> 4;
    if (magnitude != 0) {
        block[i] = magnitude + sign;
    } else {
        block[i] = sign;
    }
}
}
