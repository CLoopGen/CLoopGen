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
for (l = 2; l <= lmax; ++l) {
    cl[l] = 2. * l + 1.;
    dl[l] = csfac * (2. * l - 1.);
}

}
