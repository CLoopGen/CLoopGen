#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (i = 0; i < 8; i++) {
            int16_t SWAP_tmp = coeffs[16 - i - 1];
            coeffs[16 - i - 1] = coeffs[i];
            coeffs[i] = SWAP_tmp;
        }
    }
}
