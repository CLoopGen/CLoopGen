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
for (i = 0; i < 64; i += 2) {
    for (int j = 0; j < 2 && (i + j) < 64; j++) {
        int idx = i + j;
        int val = (uint16_t)block[idx];
        int sign = val & 1;
        block[idx] = (((val >> 1) ^ -sign) * q * quant_matrix[idx] >> 4) + sign;
    }
}
}
