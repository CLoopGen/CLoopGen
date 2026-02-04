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
    for (m = 1; m <= mmax; m += 2) {
        k += 4;
        for (l = m + 2; l <= lmax - 1; l += 2) {
            double inv_sqrt_sum = 1.0 / sqrts[l + m];
            double inv_sqrt_diff = 1.0 / sqrts[l - m];
            alm[2 * k] = ((2. * l - 1.) * inv_sqrt_sum) * inv_sqrt_diff;
            alm[2 * k + 1] = -(sqrts[l + m - 1] * inv_sqrt_sum) * (sqrts[l - m - 1] * inv_sqrt_diff);
            ++k;
            if (l + 1 < lmax) {
                alm[2 * k] = ((2. * (l + 1) - 1.) / sqrts[l + 1 + m]) / sqrts[l + 1 - m];
                alm[2 * k + 1] = -(sqrts[l + 1 + m - 1] / sqrts[l + 1 + m]) * (sqrts[l + 1 - m - 1] / sqrts[l + 1 - m]);
                ++k;
            }
        }
    }
}
