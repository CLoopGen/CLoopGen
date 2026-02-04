#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float exponent_tab[50];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_val;
    for (i = 0; i < 25; i++) {
        temp_val = 1.F / (1 << i);
        exponent_tab[i * 2] = temp_val;
        exponent_tab[i * 2 + 1] = 0.70710678118654757F * temp_val;
    }
}
