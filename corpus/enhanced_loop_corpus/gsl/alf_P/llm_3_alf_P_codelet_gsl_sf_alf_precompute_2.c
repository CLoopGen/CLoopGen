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
    // Variant 2: Memory Access Pattern Modification - Consecutive-like access using local accumulation and batch update
    double temp_real, temp_imag;
    for (m = 0; m <= mmax; ++m) {
        if (m > 0) {
            k += 2;
        }
        for (l = m + 2; l <= lmax; ++l) {
            // Compute values first using current l, m, k
            temp_real = (sqrts[2 * l + 1] / sqrts[l + m]) * (sqrts[2 * l - 1] / sqrts[l - m]);
            temp_imag = -(sqrts[l + m - 1] / sqrts[l + m]) * 
                        (sqrts[l - m - 1] / sqrts[l - m]) * 
                        (sqrts[2 * l + 1] / sqrts[2 * l - 3]);

            // Perform consecutive-style writes by updating both components before incrementing k
            alm[2 * k]     = temp_real;
            alm[2 * k + 1] = temp_imag;

            ++k;
        }
    }
}
