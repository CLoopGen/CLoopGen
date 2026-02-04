#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i += 2) {
        int16_t SWAP_tmp1 = coeffs[15 - i];
        int16_t SWAP_tmp2 = coeffs[14 - i];
        coeffs[15 - i] = coeffs[i];
        coeffs[i] = SWAP_tmp1;
        if (i + 1 < 8) {
            coeffs[14 - i] = coeffs[i + 1];
            coeffs[i + 1] = SWAP_tmp2;
        }
    }
}
