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
    // Variant 1: Consecutive Memory Access via Precomputed Indices
    // Instead of computing 2*k repeatedly, we precompute and increment index to promote consecutive access
    size_t idx = 0; // Local index to track position in alm (replaces 2*k)
    for (m = 0; m <= mmax; ++m) {
        if (m > 0) {
            idx += 4; // Because k += 2 => idx = 2*k increases by 4
        }
        for (l = m + 2; l <= lmax; ++l) {
            alm[idx]     = (sqrts[2 * l + 1] / sqrts[l + m]) * (sqrts[2 * l - 1] / sqrts[l - m]);
            alm[idx + 1] = -(sqrts[l + m - 1] / sqrts[l + m]) * (sqrts[l - m - 1] / sqrts[l - m]) * (sqrts[2 * l + 1] / sqrts[2 * l - 3]);
            idx += 2;
        }
    }
}
