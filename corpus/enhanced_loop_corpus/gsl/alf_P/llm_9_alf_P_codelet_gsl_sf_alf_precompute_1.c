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
    for (m = 2; m <= mmax; m += 2) {
        k += 2;
        for (l = m + 4; l <= lmax; ++l) {
            double temp_sum = sqrts[l + m];
            double temp_diff = sqrts[l - m];
            alm[2 * k] = (2. * l - 1.) / (temp_sum * temp_diff);
            if (l > m + 4) {
                alm[2 * k + 1] = -(sqrts[l + m - 1] / temp_sum) * (sqrts[l - m - 1] / temp_diff);
            } else {
                alm[2 * k + 1] = 0.0;
            }
            ++k;
        }
    }
}
