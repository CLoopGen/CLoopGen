#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Np;
extern double *t;
extern double increment;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Iterates from the last element to the first
    for (i = Np - 1; i >= 0; i--) {
        t[i] = increment * (double)i;
    }
}
