#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t lmax;
extern  double csfac;
extern double *cl;
extern double *dl;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 2; i <= lmax; ++i) {
        for (l = i; l <= i; ++l) {
            cl[l] = 2. * l + 1.;
            dl[l] = csfac * (2. * l - 1.);
        }
    }
}
