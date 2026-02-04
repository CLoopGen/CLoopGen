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
    // Variant 1: Strided memory access with step size 2, processing even indices first, then odd
    int j;
    for (j = 0; j < 2; j++) {
        for (i = j; i < 64; i += 2) {
            int val = (uint16_t)block[i];
            int sign = val & 1;
            block[i] = (((val >> 1) ^ -sign) * q * quant_matrix[i] >> 4) + sign;
        }
    }
}
