#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *coeff_data;
extern int run;
extern int coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t local_coeff = coeff;
    for (i = 0; i < run; i++) {
        *coeff_data++ = local_coeff;
        local_coeff = local_coeff ^ 0x1; // Introduce artificial dependency on previous value
    }
}
