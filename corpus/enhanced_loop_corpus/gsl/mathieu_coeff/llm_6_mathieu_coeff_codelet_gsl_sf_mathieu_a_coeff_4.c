#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[100];
    for (ii = 0; ii < 100; ii++) {
        temp[ii] = coeff[ii] / sum;
    }
    for (ii = 0; ii < 100; ii++) {
        coeff[ii] = temp[ii];
    }
}
