#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 99; ii >= 0; ii--) {
        if (ii < 99)
            coeff[ii] = coeff[ii + 1]; // Introduce loop-carried dependence (WAW and RAW)
        else
            coeff[ii] = 0.;
    }
}
