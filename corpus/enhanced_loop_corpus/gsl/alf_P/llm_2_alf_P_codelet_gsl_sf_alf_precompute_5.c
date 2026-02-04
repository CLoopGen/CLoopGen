#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t lmax;
extern  size_t mmax;
extern double *alm;
extern size_t l;
extern size_t m;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Precomputed Indices
    size_t idx = 0;
    for (m = 0; m <= mmax; ++m) {
        if (m > 0) {
            k += 2;
        }
        for (l = m + 2; l <= lmax; ++l) {
            size_t base = 2 * k;
            // Force consecutive access pattern by writing both elements in order
            alm[base]     = (2. * l - 1.) / ((double)(l - m));
            alm[base + 1] = -(l + m - 1.) / ((double)(l - m));
            ++k;
        }
    }
}
