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
        size_t idx_alm = 2 * k;
        size_t idx_sqrts_l_plus_m = l + m;
        size_t idx_sqrts_l_minus_m = l - m;
        alm[idx_alm] = (sqrts[2 * l + 1] / sqrts[idx_sqrts_l_plus_m]) * (sqrts[2 * l - 1] / sqrts[idx_sqrts_l_minus_m]);
        alm[idx_alm + 1] = -(sqrts[idx_sqrts_l_plus_m - 1] / sqrts[idx_sqrts_l_plus_m]) * 
                           (sqrts[idx_sqrts_l_minus_m - 1] / sqrts[idx_sqrts_l_minus_m]) * 
                           (sqrts[2 * l + 1] / sqrts[2 * l - 3]);
        ++k;
    }
}
}
