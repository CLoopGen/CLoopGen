#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[100];
    for (ii = 0; ii < 100; ii++) {
        temp[ii] = 0.;
        coeff[ii] = temp[ii];
    }
}
