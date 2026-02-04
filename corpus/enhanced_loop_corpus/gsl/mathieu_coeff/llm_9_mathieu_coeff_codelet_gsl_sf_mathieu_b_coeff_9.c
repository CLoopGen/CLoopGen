#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 50; ii++) {
        coeff[2*ii] = 0.;
        coeff[2*ii + 1] = 0.;
        coeff[2*ii] += 1.0;
        coeff[2*ii] -= 1.0;
    }
}
