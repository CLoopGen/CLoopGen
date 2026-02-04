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
    for (m = 1; m <= mmax; ++m) {
        k += 2;
        l = m + 2;
        if (l <= lmax) {
            do {
                alm[2 * k] = ((2. * l - 1.) / sqrts[l + m]) / sqrts[l - m];
                alm[2 * k + 1] = -(sqrts[l + m - 1] / sqrts[l + m]) * (sqrts[l - m - 1] / sqrts[l - m]);
                ++k;
                ++l;
            } while (l <= lmax);
        }
    }
}
