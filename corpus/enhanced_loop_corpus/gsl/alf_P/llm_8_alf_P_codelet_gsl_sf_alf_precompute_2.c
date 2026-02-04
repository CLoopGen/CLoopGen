#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t lmax;
extern  size_t mmax;
extern double *alm;
extern double *sqrts;
extern size_t l;
extern size_t m;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = 0; m <= mmax; ++m) {
    if (m > 0) {
        k += 2;
    }
    for (l = m + 2; l <= lmax; ++l) {
        double temp1 = sqrts[2 * l + 1] / sqrts[l + m];
        double temp2 = sqrts[2 * l - 1] / sqrts[l - m];
        alm[2 * k] = temp1 * temp2;
        
        double temp3 = sqrts[l + m - 1] / sqrts[l + m];
        double temp4 = sqrts[l - m - 1] / sqrts[l - m];
        double temp5 = sqrts[2 * l + 1] / sqrts[2 * l - 3];
        alm[2 * k + 1] = -(temp3 * temp4 * temp5);
        
        ++k;
    }
}
}
