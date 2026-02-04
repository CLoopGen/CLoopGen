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
    size_t temp_k = k; // Introduce local temporary to break direct WAW on k
    for (m = 0; m <= mmax; ++m) {
        if (m > 0) {
            temp_k += 2;
        }
        for (l = m + 2; l <= lmax; ++l) {
            size_t idx = 2 * temp_k;
            alm[idx] = (2. * l - 1.) / ((double)(l - m));
            alm[idx + 1] = -(l + m - 1.) / ((double)(l - m));
            ++temp_k;
        }
    }
    k = temp_k; // Write back final value of k only once at the end
}
