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
        k += 4; // Adjusted increment to maintain index consistency due to larger step
    }
    for (l = m + 2; l <= lmax; l += 2) {
        double ratio1 = sqrts[2 * l + 1] / sqrts[l + m];
        double ratio2 = sqrts[2 * l - 1] / sqrts[l - m];
        alm[2 * k] = ratio1 * ratio2;

        if (l >= 2) {
            double factor = sqrts[2 * l + 1] / sqrts[2 * l - 3];
            alm[2 * k + 1] = -(sqrts[l + m - 1] / sqrts[l + m]) * 
                             (sqrts[l - m - 1] / sqrts[l - m]) * factor;
        } else {
            alm[2 * k + 1] = 0.0;
        }
        k += 2; // Increase k by 2 per iteration due to reduced loop frequency
    }
}
}
