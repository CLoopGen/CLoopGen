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
    // Variant 1: Increase loop nesting depth by splitting the inner loop into two sequential inner loops
    // This increases nesting depth logically by introducing a second inner loop at the same level
    for (m = 0; m <= mmax; ++m) {
        if (m > 0) {
            k += 2;
        }
        // First part: handle even indices and initialization-like computations
        for (l = m + 2; l <= lmax; ++l) {
            alm[2 * k] = (sqrts[2 * l + 1] / sqrts[l + m]) * (sqrts[2 * l - 1] / sqrts[l - m]);
            ++k;
        }
        // Second part: recompute k and fill odd indices in reverse order to simulate different access pattern
        // We reset k to the starting point of this m-block and proceed differently
        size_t temp_k = k - (lmax - (m + 2) + 1); // backtrack to start of current m block
        for (l = m + 2; l <= lmax; ++l) {
            alm[2 * temp_k + 1] = -(sqrts[l + m - 1] / sqrts[l + m]) * (sqrts[l - m - 1] / sqrts[l - m]) * (sqrts[2 * l + 1] / sqrts[2 * l - 3]);
            ++temp_k;
        }
    }
}
