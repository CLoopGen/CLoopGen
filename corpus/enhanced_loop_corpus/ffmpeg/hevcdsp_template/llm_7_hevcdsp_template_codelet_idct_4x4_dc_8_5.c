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
    for (j = 0; j < 4; j++) {
        int16_t local_coeff = coeff ^ j; // Break loop-carried dependency on coeff
        for (i = 0; i < 4; i += 2) {
            coeffs[i + j * 4] = local_coeff;           // Write at i
            coeffs[i + j * 4 + 1] = local_coeff + 1;   // Introduce anti-dependence (WAR) with next iteration
        }
    }
}
