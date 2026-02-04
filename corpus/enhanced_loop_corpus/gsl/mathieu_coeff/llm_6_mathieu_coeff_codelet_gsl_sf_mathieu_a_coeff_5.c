#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 100; ii++) {
        if (ii > 0)
            coeff[ii] = coeff[ii-1]; // Introduce RAW dependency: current iteration reads previous write
        else
            coeff[ii] = 0.;
    }
}
