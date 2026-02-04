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
for (m = 0; m <= mmax; m += 2) {
    if (m > 0) {
        k += 4; // Adjusted increment to maintain index consistency due to stride change
    }
    for (l = m + 2; l <= lmax; l += 2) {
        double ratio1 = sqrts[2 * l + 1] / (sqrts[l + m] * sqrts[l - m]);
        double ratio2 = sqrts[2 * l - 1];
        alm[2 * k] = ratio1 * ratio2;

        if (l >= 4) { // Ensure safe access for lower indices
            double decay = (sqrts[l + m - 1] * sqrts[l - m - 1] * sqrts[2 * l + 1]) /
                          (sqrts[l + m] * sqrts[l - m] * sqrts[2 * l - 3]);
            alm[2 * k + 1] = -decay;
        }
        ++k;
    }
}
}
