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
    // Variant 1: Memory Access Pattern Modification - Consecutive Array Access via Pointer Arithmetic
    double *alm_ptr = alm;
    const double *sqrts_ptr = sqrts;
    for (m = 0; m <= mmax; ++m) {
        if (m > 0) {
            k += 2;
        }
        for (l = m + 2; l <= lmax; ++l) {
            size_t idx1 = 2 * l + 1;
            size_t idx2 = l + m;
            size_t idx3 = 2 * l - 1;
            size_t idx4 = l - m;
            alm_ptr[0] = (sqrts_ptr[idx1] / sqrts_ptr[idx2]) * (sqrts_ptr[idx3] / sqrts_ptr[idx4]);
            
            size_t idx5 = l + m - 1;
            size_t idx6 = l - m - 1;
            size_t idx7 = 2 * l - 3;
            alm_ptr[1] = -(sqrts_ptr[idx5] / sqrts_ptr[idx2]) * (sqrts_ptr[idx6] / sqrts_ptr[idx4]) * (sqrts_ptr[idx1] / sqrts_ptr[idx7]);
            
            alm_ptr += 2;
            ++k;
        }
    }
}
