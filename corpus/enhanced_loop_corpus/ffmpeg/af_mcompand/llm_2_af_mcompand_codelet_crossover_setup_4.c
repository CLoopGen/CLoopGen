#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x[9];
extern double norm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element, forward and backward pass)
    for (norm = x[6], i = 0; i < 9; i += 2)
        x[i] /= norm;
    for (i = 1; i < 9; i += 2)
        x[i] /= norm;
}
