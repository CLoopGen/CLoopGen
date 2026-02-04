#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 50; ii++) {
        coeff[ii * 2] = 0.0;
        coeff[ii * 2 + 1] = 1.0 - 1.0; // Increased arithmetic operations per iteration
    }
}
