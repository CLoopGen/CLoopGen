#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int l;
extern  int m;
extern  double x;
extern double p_ellm2;
extern double p_ellm1;
extern double p_ell;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with modified trip count and simplified recurrence
    // Trip count reduced by increasing loop increment and skipping every other iteration
    // Also replaced full recurrence with a lighter approximation under certain conditions

    for (ell = m + 2; ell <= l; ell += 2) {  // Half the number of iterations
        if (ell % 4 == 0) {
            // Full computation on every fourth eligible index
            p_ell = (x * (2 * ell - 1) * p_ellm1 - (ell + m - 1) * p_ellm2) / (ell - m);
        } else {
            // Light computation: damped propagation without full dependency
            p_ell = x * p_ellm1 * (1.0 + 1.0 / ell);
        }
        p_ellm2 = p_ellm1;
        p_ellm1 = p_ell;
    }
}
