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
    int val1 = (uint16_t)block[i];
    int sign1 = val1 & 1;
    int result1 = (((val1 >> 1) ^ -sign1) * q * quant_matrix[i] >> 4) + sign1;
    block[i] = result1;

    if (i + 1 < 64) {
        int val2 = (uint16_t)block[i + 1];
        int sign2 = val2 & 1;
        int result2 = (((val2 >> 1) ^ -sign2) * q * quant_matrix[i + 1] >> 4) + sign2;
        block[i + 1] = result2;
    }
}
}
