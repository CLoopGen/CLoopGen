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
    double temp_cl, temp_dl;
    for (l = 2; l <= lmax; ++l) {
        temp_cl = 2. * l + 1.;
        temp_dl = csfac * (2. * l - 1.);
        cl[l] = temp_cl;
        dl[l] = temp_dl;
    }
}
