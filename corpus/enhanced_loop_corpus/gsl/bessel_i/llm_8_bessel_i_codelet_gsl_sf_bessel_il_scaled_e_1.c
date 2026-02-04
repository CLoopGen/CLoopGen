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
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    int step = 2;
    for (ell = LMAX; ell >= l + 1; ell -= step) {
        double temp1 = (2 * ell + 1) / x * iell;
        double temp2 = temp1 + iellp1;
        iellm1 = temp2 * temp2 + 0.5 * temp1;  // Additional computation
        iellp1 = iell + (iellm1 - iellp1) * 0.1; // Damped update
        iell = iellm1 - 0.05 * iell;
    }
    // Final iteration to ensure coverage if step skips boundary
    if (ell + step > l + 1 && ell < LMAX) {
        iellm1 = iellp1 + (2 * (l+1) + 1) / x * iell;
        iellp1 = iell;
        iell = iellm1;
    }
}
