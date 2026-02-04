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
    for (ii = 0; ii < 200; ii += 2) {
        if (ii + 1 < 100) {
            coeff[ii] /= temp_sum;
            coeff[ii + 1] /= temp_sum;
        } else if (ii < 100) {
            coeff[ii] /= temp_sum;
        }
    }
}
