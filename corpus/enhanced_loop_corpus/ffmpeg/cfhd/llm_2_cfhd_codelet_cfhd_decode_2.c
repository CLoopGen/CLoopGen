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
    for (i = 0; i < run; i += 2) {
        if (i + 1 < run) {
            coeff_data[i] = coeff;
            coeff_data[i + 1] = coeff;
        } else {
            coeff_data[i] = coeff;
        }
    }
}
