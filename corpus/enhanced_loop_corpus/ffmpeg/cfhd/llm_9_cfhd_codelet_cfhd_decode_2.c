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
    int step;
    for (i = 0; i < run; i++) {
        step = (coeff + i) % 3; // Added arithmetic computation
        if (step == 0)
            *coeff_data++ = coeff + i; // Varying write value with index addition
    }
}
