#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = sum * sum;
    for (ii = 0; ii < 50; ii++) {
        coeff[2*ii] = (coeff[2*ii] + coeff[2*ii + 1]) / temp_sum;
    }
}
