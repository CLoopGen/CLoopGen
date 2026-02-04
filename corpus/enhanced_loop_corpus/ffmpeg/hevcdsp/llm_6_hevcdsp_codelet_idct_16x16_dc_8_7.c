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
        for (i = 0; i < 16; i++) {
            int idx = i + j * 16;
            coeffs[idx] = coeff;
            if (idx > 0) {
                coeffs[idx] += (coeffs[idx - 1] & 0x1); // Introduce RAW dependency: current value depends on previous
            }
        }
    }
}
