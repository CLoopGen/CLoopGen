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
    for (m = 1; m <= mmax; ++m) {
        k += 2;
        for (l = m + 2; l <= lmax; ++l) {
            size_t idx = 2 * k;
            double sum_plus_m = sqrts[l + m];
            double sum_minus_m = sqrts[l - m];
            alm[idx] = ((2. * l - 1.) / sum_plus_m) / sum_minus_m;
            alm[idx + 1] = -(sqrts[l + m - 1] / sum_plus_m) * (sqrts[l - m - 1] / sum_minus_m);
            ++k;
        }
    }
}
