#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

// External variables as referenced in the loop
int l;
double lambda;
double xi;
double Pellp1;
double Pell;
double Pellm1;
int ell;

// Initialization function to set values for all required variables
void init_vars() {
    // Set l to a value that makes the loop run approximately 0.01 seconds
    // On typical modern CPUs, each iteration is a few cycles; assume ~100 ns per iteration for safety
    // For 0.01 s total: 0.01 / 1e-7 = about 100,000 iterations
    l = 100000;

    lambda = 0.5;
    xi = 1.2;

    // Initialize Pellp1 and Pell to some physical-like starting values
    Pellp1 = 1.0;
    Pell = 0.5;

    // Initial value for Pellm1 will be overwritten in first loop iteration, but initialize anyway
    Pellm1 = 0.0;

    // ell is initialized in the loop itself (from l down to 0), so no need to set here beyond consistency
    ell = l;
}