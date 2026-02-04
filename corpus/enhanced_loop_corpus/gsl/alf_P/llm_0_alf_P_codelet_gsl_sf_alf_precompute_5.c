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
        l = m + 2;
        while (l <= lmax) {
            alm[2 * k] = (2. * l - 1.) / ((double)(l - m));
            alm[2 * k + 1] = -(l + m - 1.) / ((double)(l - m));
            ++k;
            ++l;
        }
    }
}
