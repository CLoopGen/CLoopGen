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
    size_t temp_k;
    for (m = 0; m <= mmax; ++m) {
        temp_k = k;
        if (m > 0) {
            k += 2;
            temp_k += 2;
        }
        for (l = m + 2; l <= lmax; ++l) {
            size_t idx = 2 * temp_k;
            alm[idx] = (sqrts[2 * l + 1] / sqrts[l + m]) * (sqrts[2 * l - 1] / sqrts[l - m]);
            alm[idx + 1] = -(sqrts[l + m - 1] / sqrts[l + m]) * (sqrts[l - m - 1] / sqrts[l - m]) * (sqrts[2 * l + 1] / sqrts[2 * l - 3]);
            ++temp_k;
        }
        k = temp_k;
    }
}
