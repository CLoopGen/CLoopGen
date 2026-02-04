#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;
extern int j;
extern int coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 16; j++) {
        int16_t temp_coeff = coeff + j; // Remove loop-carried dependency by localizing modification
        for (i = 0; i < 16; i++) {
            int idx = i + j * 16;
            coeffs[idx] = temp_coeff;
            temp_coeff ^= 0x5; // Introduce WAW and WAR via temporary reuse, but no loop-carried dependency across iterations
        }
    }
}
