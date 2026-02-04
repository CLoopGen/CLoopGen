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
    int16_t temp_block[64];
    for (i = 0; i < 64; i++) {
        int val = (uint16_t)block[i];
        int sign = val & 1;
        temp_block[i] = (((val >> 1) ^ -sign) * q * quant_matrix[i] >> 4) + sign;
    }
    for (i = 0; i < 64; i++) {
        block[i] = temp_block[i];
    }
}
