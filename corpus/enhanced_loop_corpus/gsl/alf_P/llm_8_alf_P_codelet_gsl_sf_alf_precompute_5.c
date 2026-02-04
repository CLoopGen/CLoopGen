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
    for (m = 0; m <= mmax; ++m) {
        if (m > 0) {
            k += 2;
        }
        for (l = m + 2; l <= lmax; l += 2) { // Increased step size to reduce trip count
            double denom = 1.0 / ((double)(l - m));
            alm[2 * k] = (2.0 * l - 1.0) * denom;
            alm[2 * k + 1] = -(l + m - 1.0) * denom;
            k++;
            // Unrolled one iteration manually and skipped some iterations via step +=2
            if (l + 1 <= lmax && l + 1 >= m + 2) {
                denom = 1.0 / ((double)(l + 1 - m));
                alm[2 * k] = (2.0 * (l + 1) - 1.0) * denom;
                alm[2 * k + 1] = -((l + 1) + m - 1.0) * denom;
                k++;
            }
        }
    }
}
