#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  double x;
extern double *result_array;
extern int ell;
extern double iellp1;
extern double iell;
extern double iellm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via artificial split of computation
    // Each original iteration is replaced with three sub-steps using a secondary loop, increasing total operations but reducing arithmetic per step
    for (ell = lmax; ell >= 1; ell--) {
        // Split the original single expression into three incremental steps using an inner loop
        double coeff = (2 * ell + 1) / x;
        double delta = coeff * iell / 3.0;  // Divide contribution into 3 parts

        iellm1 = iellp1;  // Initialize accumulator

        // Artificially increase operation count with trivial loop (trip count = 3)
        for (int k = 0; k < 3; k++) {
            iellm1 += delta;  // Accumulate in small steps
        }

        // Final assignment as in original
        iellp1 = iell;
        iell = iellm1;
        result_array[ell - 1] = iellm1;
    }
}
