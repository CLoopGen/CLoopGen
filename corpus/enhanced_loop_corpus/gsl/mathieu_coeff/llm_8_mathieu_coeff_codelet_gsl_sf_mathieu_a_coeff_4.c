#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 200; ii += 2) {
        if (ii + 1 < 100) {
            coeff[ii] /= sum;
            coeff[ii + 1] /= sum;
        } else if (ii < 100) {
            coeff[ii] /= sum;
        }
    }
}
