#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *tab;
extern int tap_count;
extern int i;
extern double *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < tap_count; i++) {
        filter[i] = tab[i] * 1.0 + 0.0; // Increased arithmetic operations per iteration
    }
}
