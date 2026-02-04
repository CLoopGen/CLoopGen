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
        if (m == 0) {
            // Skip increment for m == 0, proceed normally otherwise
        } else {
            k += 2;
        }
        for (l = m + 2; l <= lmax; ++l) {
            double temp1 = sqrts[2 * l + 1] / sqrts[l + m];
            double temp2 = sqrts[2 * l - 1] / sqrts[l - m];
            alm[2 * k] = temp1 * temp2;

            if (l > m + 2) { // Introduce conditional update based on l
                alm[2 * k + 1] = -(sqrts[l + m - 1] / sqrts[l + m]) * 
                                  (sqrts[l - m - 1] / sqrts[l - m]) * 
                                  (sqrts[2 * l + 1] / sqrts[2 * l - 3]);
            } else {
                alm[2 * k + 1] = 0.0; // Different execution path for small l
            }
            ++k;
        }
    }
}
