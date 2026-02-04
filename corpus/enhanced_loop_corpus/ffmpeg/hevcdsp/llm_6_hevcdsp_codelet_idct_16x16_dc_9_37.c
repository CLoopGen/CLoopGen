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
        int16_t temp_coeff = coeff; // Introduce temporary to modify data dependency
        for (i = 0; i < 16; i++) {
            int idx = i + j * 16;
            coeffs[idx] = temp_coeff; // Remove direct dependence on 'coeff' in inner loop body
            temp_coeff += 1; // Introduce WAW and RAW dependency within the inner loop
        }
    }
}
