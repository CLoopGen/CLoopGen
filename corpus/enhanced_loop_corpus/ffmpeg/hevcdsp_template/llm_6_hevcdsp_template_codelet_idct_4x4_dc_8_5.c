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
    int16_t temp[4];
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            temp[i] = coeff + (i > 0 ? temp[i-1] : 0); // Introduce RAW dependency across iterations
        }
        for (i = 0; i < 4; i++) {
            coeffs[i + j * 4] = temp[i]; // Remove direct assignment, add WAW via temp buffer
        }
    }
}
