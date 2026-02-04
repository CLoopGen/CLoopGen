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
        double inv_l = 1.0 / (double)l;
        double val1 = 2. - inv_l;
        double val2 = -(1. - inv_l);
        alm[2 * k] = val1;
        alm[2 * k + 1] = val2;
        k++;
    }
}
