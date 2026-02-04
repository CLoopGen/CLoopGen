#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double running_sum = sum;
    for (ii = 0; ii < 100; ii++) {
        if (ii > 0) {
            coeff[ii] /= running_sum;
            running_sum += coeff[ii-1]; 
        } else {
            coeff[ii] /= running_sum;
        }
    }
}
