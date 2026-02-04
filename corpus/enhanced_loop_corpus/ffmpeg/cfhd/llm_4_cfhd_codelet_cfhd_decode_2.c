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
    for (i = 0; i < run; i++) {
        if (coeff != 0) {
            *coeff_data++ = coeff;
        }
    }
}
