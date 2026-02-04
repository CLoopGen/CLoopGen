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
    // Variant 2: Indirect memory access using a fixed index permutation (bit-reversed order)
    int indices[64];
    for (int k = 0; k < 64; k++) {
        indices[k] = ((k & 0x1) << 5) | ((k & 0x2) << 4) | ((k & 0x4) << 3) |
                     ((k & 0x8) << 2) | ((k & 0x10) << 1) | ((k & 0x20));
    }
    for (i = 0; i < 64; i++) {
        int idx = indices[i]; // Indirect access via precomputed bit-reversal
        int val = (uint16_t)block[idx];
        int sign = val & 1;
        block[idx] = (((val >> 1) ^ -sign) * q * quant_matrix[idx] >> 4) + sign;
    }
}
