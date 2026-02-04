#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t n_coeffs;
extern int16_t *block_dup;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t step;
    for (cnt = 0; cnt < (n_coeffs >> 4); cnt++) {
        for (step = 0; step < 2; step++) {
            block_dup += 8;
        }
    }
}
