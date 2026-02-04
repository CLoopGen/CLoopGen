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
    int temp = coeff;
    for (i = 0; i < run; i++) {
        temp += *coeff_data;
        *coeff_data++ = temp;
    }
}
