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
        size_t base_k;
        if (m == 0) {
            base_k = 0;
        } else {
            base_k = k;
            k += 2;
        }
        size_t iter_count = 0;
        for (l = m + 2; l <= lmax; ++l) {
            size_t index = base_k + iter_count;
            double temp1 = (sqrts[2 * l + 1] / sqrts[l + m]) * (sqrts[2 * l - 1] / sqrts[l - m]);
            double temp2 = -(sqrts[l + m - 1] / sqrts[l + m]) * (sqrts[l - m - 1] / sqrts[l - m]) * (sqrts[2 * l + 1] / sqrts[2 * l - 3]);
            alm[2 * index] = temp1;
            alm[2 * index + 1] = temp2;
            ++iter_count;
        }
        if (m > 0) {
            k += iter_count;
        } else {
            k = iter_count;
        }
    }
}
