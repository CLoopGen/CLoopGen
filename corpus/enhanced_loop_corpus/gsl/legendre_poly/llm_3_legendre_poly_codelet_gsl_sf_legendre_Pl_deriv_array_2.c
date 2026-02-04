#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  double x;
extern double *result_deriv_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    // Simulate indirect access via an auxiliary index array to alter access pattern
    int *indices = (int*)malloc((lmax - 1) * sizeof(int));
    if (!indices) return; // Handle allocation failure

    // Populate index map: reordering access from 2..lmax into reverse order
    for (int i = 0; i <= lmax - 2; i++) {
        indices[i] = lmax - i; // maps i to descending index starting from lmax down
    }

    for (int i = 0; i <= lmax - 2; i++) {
        ell = indices[i];
        if (ell < 2 || ell > lmax) continue; // Ensure bounds
        const double pre = 0.5 * ell * (ell + 1.);
        result_deriv_array[ell] = pre * (1. - 0.25 * (1. - x) * (ell + 2.) * (ell - 1.));
    }

    free(indices);
}
