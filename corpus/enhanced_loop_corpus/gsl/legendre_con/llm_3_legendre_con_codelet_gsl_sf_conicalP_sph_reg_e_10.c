#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int l;
extern  double lambda;
extern  double xi;
extern double Pellp1;
extern double Pell;
extern double Pellm1;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using consecutive array access in reverse order
    // We refactor the recurrence into an array-based backward traversal with unit stride
    // This improves spatial locality and reflects a more cache-friendly access pattern
    int n = l + 3;
    double *P = (double*)alloca(n * sizeof(double));
    int offset = 1;

    // Initialize boundary conditions at offset indices
    P[offset + l + 1] = Pellp1;
    P[offset + l]     = Pell;

    for (ell = l; ell >= 0; ell--) {
        double d = (ell + 1.) * (ell + 1.) + lambda * lambda;
        P[offset + ell - 1] = (2. * ell + 1.) * xi * P[offset + ell] - d * P[offset + ell + 1];
    }

    // Update global output variables from computed values
    Pellm1 = P[offset - 1];
    Pell   = P[offset - 1];
    Pellp1 = P[offset];
}
