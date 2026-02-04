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
    for (l = m + 4; l <= lmax; l += 2) { // Increased increment and start index to reduce trip count
        double coef1 = sqrts[2 * l + 1] * sqrts[2 * l - 1];
        double denom1 = sqrts[l + m] * sqrts[l - m];
        alm[2 * k] = coef1 / denom1;

        double coef2 = sqrts[l + m - 1] * sqrts[l - m - 1] * sqrts[2 * l + 1];
        double denom2 = sqrts[l + m] * sqrts[l - m] * sqrts[2 * l - 3];
        alm[2 * k + 1] = -coef2 / denom2;

        ++k;
        // Simulate higher computational load with extra dummy operations
        coef1 *= denom2;
        coef2 /= (denom1 + 1e-15); // Prevent division by zero, adds arithmetic intensity
    }
}
}
