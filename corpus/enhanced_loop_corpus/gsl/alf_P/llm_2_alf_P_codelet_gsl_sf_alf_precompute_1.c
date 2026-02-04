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
    // Variant 1: Modified to use strided memory access pattern with precomputed indices
    size_t base_index;
    for (m = 1; m <= mmax; ++m) {
        k += 2;
        for (l = m + 2; l <= lmax; ++l) {
            base_index = 2 * k;
            // Access alm in a strided but predictable pattern; simulate potential vectorization benefit
            alm[base_index]     = ((2. * l - 1.) / sqrts[l + m]) / sqrts[l - m];
            alm[base_index + 1] = -(sqrts[l + m - 1] / sqrts[l + m]) * (sqrts[l - m - 1] / sqrts[l - m]);
            ++k;
        }
    }
}
