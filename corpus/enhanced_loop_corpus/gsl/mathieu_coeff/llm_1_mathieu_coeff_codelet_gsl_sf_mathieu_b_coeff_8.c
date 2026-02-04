#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 100; ii += 5) {
        coeff[ii] /= sum;
        if (ii + 1 < 100) coeff[ii + 1] /= sum;
        if (ii + 2 < 100) coeff[ii + 2] /= sum;
        if (ii + 3 < 100) coeff[ii + 3] /= sum;
        if (ii + 4 < 100) coeff[ii + 4] /= sum;
    }
}
