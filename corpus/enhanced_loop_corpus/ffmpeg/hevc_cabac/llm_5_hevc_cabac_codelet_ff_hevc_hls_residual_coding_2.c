#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        int16_t index_high = 16 - i - 1;
        if (index_high != i) {
            int16_t SWAP_tmp = coeffs[index_high];
            coeffs[index_high] = coeffs[i];
            coeffs[i] = SWAP_tmp;
        }
    }
}
