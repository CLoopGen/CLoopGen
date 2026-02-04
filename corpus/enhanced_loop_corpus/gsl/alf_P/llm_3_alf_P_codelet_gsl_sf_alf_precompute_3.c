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
    // Variant 2: Strided Memory Access with Pointer Arithmetic
    // Use pointer arithmetic with stride to access alm elements, simulating a strided pattern
    double *alm_ptr = alm; // Pointer to current position in alm
    for (m = 0; m <= mmax; ++m) {
        if (m > 0) {
            k += 2;
            alm_ptr += 4; // Advance pointer by 4 doubles (since 2*k increases by 4 elements)
        }
        for (l = m + 2; l <= lmax; ++l) {
            // Direct pointer access with fixed offset
            *(alm_ptr++) = (sqrts[2 * l + 1] / sqrts[l + m]) * (sqrts[2 * l - 1] / sqrts[l - m]);
            *(alm_ptr++) = -(sqrts[l + m - 1] / sqrts[l + m]) * (sqrts[l - m - 1] / sqrts[l - m]) * (sqrts[2 * l + 1] / sqrts[2 * l - 3]);
            ++k;
        }
    }
}
