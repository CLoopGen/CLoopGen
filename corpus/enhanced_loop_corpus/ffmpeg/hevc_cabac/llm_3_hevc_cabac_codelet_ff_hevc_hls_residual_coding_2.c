#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[8] = {0, 2, 4, 6, 8, 10, 12, 14}; // Strided access: even indices
    for (i = 0; i < 8; i++) {
        int idx1 = indices[i];
        int idx2 = 15 - idx1;
        int16_t SWAP_tmp = coeffs[idx1];
        coeffs[idx1] = coeffs[idx2];
        coeffs[idx2] = SWAP_tmp;
    }
}
