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
        if (l % 2 == 0) {
            alm[2 * k] = 2. - 1. / (double)l;
        } else {
            alm[2 * k] = 1.5; // alternate value for odd l
        }
        alm[2 * k + 1] = -(1. - 1. / (double)l);
        ++k;
    }
}
