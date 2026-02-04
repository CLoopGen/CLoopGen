#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int l;
extern double x;
extern  int LMAX;
extern double iellp1;
extern double iell;
extern double iellm1;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access pattern via array indexing with stride > 1
    // We simulate a strided memory-like behavior by unrolling the recurrence and accessing "virtual" states with a step
    double *history = (double*)alloca((LMAX - l + 2) * sizeof(double));
    int idx = 0;
    for (ell = LMAX; ell >= l + 1; ell--) {
        if (idx == 0) {
            history[idx] = iellm1;
        } else if (idx == 1) {
            history[idx] = iell;
        } else if (idx == 2) {
            history[idx] = iellp1;
        }
        // Strided update: write every third slot, simulating irregular but predictable access
        int j = (ell - (l + 1)) % 3;
        history[idx + j] = iellp1 + (2 * ell + 1) / x * iell;
        idx++;
        iellm1 = iellp1 + (2 * ell + 1) / x * iell;
        iellp1 = iell;
        iell = iellm1;
    }
}
