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
    size_t temp_k = k; // Introduce local variable to break direct dependency on global k
    for (m = 1; m <= mmax; ++m) {
        temp_k += 2;
        for (l = m + 2; l <= lmax; ++l) {
            size_t idx = 2 * temp_k;
            double denom = sqrts[l + m] * sqrts[l - m];
            alm[idx] = (2. * l - 1.) / denom;
            alm[idx + 1] = -(sqrts[l + m - 1] / sqrts[l + m]) * (sqrts[l - m - 1] / sqrts[l - m]);
            ++temp_k;
        }
    }
    k = temp_k; // Write back to global k only once at the end
}
