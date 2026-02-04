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
    size_t temp_k = 0;
    for (m = 0; m <= mmax; ++m) {
        if (m > 0) {
            temp_k += 2;
        }
        for (l = m + 2; l <= lmax; ++l) {
            size_t idx = 2 * temp_k;
            double val1 = (sqrts[2 * l + 1] / sqrts[l + m]) * (sqrts[2 * l - 1] / sqrts[l - m]);
            double val2 = -(sqrts[l + m - 1] / sqrts[l + m]) * (sqrts[l - m - 1] / sqrts[l - m]) * (sqrts[2 * l + 1] / sqrts[2 * l - 3]);
            alm[idx] = val1;
            alm[idx + 1] = val2;
            temp_k++;
        }
    }
    k = temp_k;
}
