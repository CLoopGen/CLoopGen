#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int l;
extern  double x;
extern double Qellp1;
extern double Qell;
extern double Qellm1;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive array-like access using offset indexing
    // Simulate consecutive memory layout access by unrolling two iterations per loop pass
    // This mimics vectorizable or cache-friendly access patterns
    for (ell = l; ell > 1; ell -= 2) {
        // First iteration of pair
        Qellm1 = (x * (2. * ell + 1.) * Qell - (ell + 1.) * Qellp1) / ell;
        Qellp1 = Qell;
        Qell = Qellm1;

        // Second iteration of pair
        ell--;
        Qellm1 = (x * (2. * ell + 1.) * Qell - (ell + 1.) * Qellp1) / ell;
        Qellp1 = Qell;
        Qell = Qellm1;
    }
    // Handle remaining single iteration if l is odd
    if (ell == 1) {
        Qellm1 = (x * (2. * ell + 1.) * Qell - (ell + 1.) * Qellp1) / ell;
        Qellp1 = Qell;
        Qell = Qellm1;
    }
}
