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
    // Variant 2: Reduced computational intensity with expanded trip count and simplified arithmetic
    int trip_count_factor = 3;
    for (ell = LMAX * trip_count_factor; ell >= (l + 1) * trip_count_factor; ell--) {
        // Scale down ell to maintain approximate semantic consistency
        int scaled_ell = ell / trip_count_factor;
        iellm1 = iellp1 + (2.0 * scaled_ell + 1.0) * iell; // Removed division by x for simplicity
        iellp1 = iell;
        iell = iellm1 * 0.99; // Light damping to preserve numerical stability
    }
}
