#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *residual;
extern int16_t *prev_excitation;
extern int lag;
extern int offset;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride on prev_excitation
    // Instead of accessing every element based on modulo, access with a fixed stride of 2 within bounds
    int16_t *base = &prev_excitation[offset];
    int limit = 60 + 5 - 1;
    for (i = 2; i < limit; i++) {
        int index = (i - 2) % lag;
        residual[i] = base[index * 2 % lag];  // Strided access: every second element, wrapped
    }
}
