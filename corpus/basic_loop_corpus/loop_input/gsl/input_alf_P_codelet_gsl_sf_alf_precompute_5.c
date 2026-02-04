#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t lmax;
size_t mmax;
double *alm;
size_t l;
size_t m;
size_t k;

void init_vars() {
    lmax = 2000;
    mmax = lmax;
    
    size_t num_elements = 0;
    k = 0;
    for (m = 0; m <= mmax; ++m) {
        if (m > 0) {
            k += 2;
        }
        for (l = m + 2; l <= lmax; ++l) {
            num_elements = 2 * k + 2;
            ++k;
        }
    }
    
    alm = (double*)calloc(num_elements, sizeof(double));
    if (!alm) {
        exit(1);
    }
    
    l = 0;
    m = 0;
    k = 0;
}