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
        for (l = m + 2; l <= lmax; ++l) {
            size_t idx = 2 * k;
            double denom = (double)(l - m);
            alm[idx] = (2. * l - 1.) / denom;
            alm[idx + 1] = -(l + m - 1.) / denom;
            ++k;
        }
    }
}
