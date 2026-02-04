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
    // Variant 1: Consecutive memory access pattern using array indexing
    // Simulate array-based state propagation with consecutive access
    double P[3];
    for (ell = l; ell >= 0; ell--) {
        double d = (ell + 1.) * (ell + 1.) + lambda * lambda;
        P[0] = (2. * ell + 1.) * xi * P[1] + d * P[2];
        P[2] = P[1];  // shift: Pellp1 = Pell
        P[1] = P[0];  // shift: Pell = Pellm1
    }
    // Update global output values after loop
    Pellm1 = P[0];
    Pell = P[1];
    Pellp1 = P[2];
}
