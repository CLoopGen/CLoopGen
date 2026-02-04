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
    int acc = 0;
    for (i = 0; i < 64; i++) {
        int val = (uint16_t)block[i];
        int sign = val & 1;
        int magnitude = (val >> 1) ^ -sign;
        acc += magnitude; // Introduce loop-carried dependency (WAW and RAW on 'acc')
        block[i] = ((magnitude * q * quant_matrix[i] >> 4) + sign);
    }
    // Use 'acc' to avoid being optimized out, maintaining dependency
    if (acc == 0) {
        block[0] = 0;
    }
}
