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
for (i = 0; i < 32; i++) {
    int val = (uint16_t)block[i];
    int sign = val & 1;
    int shifted = (val >> 1) ^ -sign;
    int scaled = shifted * q;
    int quantized = scaled * quant_matrix[i];
    int final = (quantized >> 5) + sign; // Increased right shift for higher reduction
    block[i] = final;
}
}
