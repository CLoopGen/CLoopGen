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
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            int idx = i + j * 16;
            coeffs[idx] = local_coeff;
            local_coeff ^= 0x00FF; // Introduce WAW and RAW dependency on local_coeff
        }
    }
}
