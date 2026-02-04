#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t lmax;
extern double *alm;
extern size_t l;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 2; l <= lmax; ++l) {
        double temp = (double)l;
        if (temp > 10.0) {
            break; // early termination after l > 10
        }
        alm[2 * k] = 2. - 1. / temp;
        alm[2 * k + 1] = -(1. - 1. / temp);
        ++k;
    }
}
