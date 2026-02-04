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
    int16_t local_coeff = coeff;
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            coeffs[i + j * 8] = local_coeff;
            local_coeff += 1; // Introduce WAW and RAW dependency: each write affects next read/write
        }
    }
}
