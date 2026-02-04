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
for (j = 0; j < 32; j++) {
    int16_t temp_coeff = coeff + j; // Remove loop-carried dependency by making write value dependent only on loop-invariant + j
    for (i = 0; i < 32; i++) {
        coeffs[i * 32 + j] = temp_coeff; // Change access pattern: transpose index to create WAW independence across i
    }
}
}
