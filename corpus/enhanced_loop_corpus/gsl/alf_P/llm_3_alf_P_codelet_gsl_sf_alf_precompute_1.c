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
    // Variant 2: Use indirect (gather-like) memory access via index array simulation
    // Simulate irregular access by introducing an auxiliary index buffer (on stack if bounds known)
    // Since we don't have actual index arrays, we simulate indirect access using offset shifts
    size_t temp_k = k; // Use temporary to avoid side effects on global k if needed elsewhere
    size_t idx0, idx1;
    for (m = 1; m <= mmax; ++m) {
        temp_k += 2;
        for (l = m + 2; l <= lmax; ++l) {
            idx0 = 2 * temp_k;           // Even index
            idx1 = idx0 + 1;             // Odd index
            // Simulated indirect access: indices computed non-trivially but deterministically
            alm[idx0] = ((2. * l - 1.) / sqrts[l + m]) / sqrts[l - m];
            alm[idx1] = -(sqrts[l + m - 1] / sqrts[l + m]) * (sqrts[l - m - 1] / sqrts[l - m]);
            ++temp_k;
        }
    }
    k = temp_k; // Update global k after loop
}
