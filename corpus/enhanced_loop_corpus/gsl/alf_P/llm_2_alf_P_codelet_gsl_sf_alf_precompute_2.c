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
    // Variant 1: Memory Access Pattern Modification - Use strided access with precomputed indices
    size_t idx_alm_real, idx_alm_imag;
    for (m = 0; m <= mmax; ++m) {
        if (m > 0) {
            k += 2;
        }
        for (l = m + 2; l <= lmax; ++l) {
            // Precompute array indices to create a more predictable strided pattern
            idx_alm_real = 2 * k;
            idx_alm_imag = 2 * k + 1;

            // Strided access: accessing sqrts with fixed offsets but grouped for clarity
            alm[idx_alm_real] = (sqrts[2 * l + 1] / sqrts[l + m]) * (sqrts[2 * l - 1] / sqrts[l - m]);
            alm[idx_alm_imag] = -(sqrts[l + m - 1] / sqrts[l + m]) * 
                                (sqrts[l - m - 1] / sqrts[l - m]) * 
                                (sqrts[2 * l + 1] / sqrts[2 * l - 3]);

            ++k;
        }
    }
}
