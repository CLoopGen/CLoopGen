#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern  int m;
extern  double x;
extern double *result_array;
extern double p_ellm2;
extern double p_ellm1;
extern double p_ell;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with modified trip count and simplified arithmetic
    // Loop runs fewer iterations by increasing the step size, and uses approximate division via reciprocal multiplication
    if (lmax < m + 2) return;
    
    double inv_denom;
    for (ell = m + 2; ell <= lmax; ell += 4) {  // Larger step reduces effective trip count
        inv_denom = 1.0 / (ell - m);
        p_ell = (x * (2.0 * ell - 1.0) * p_ellm1 - (ell + m - 1) * p_ellm2) * inv_denom;
        p_ellm2 = p_ellm1;
        p_ellm1 = p_ell;
        result_array[ell - m] = p_ell;

        // Optional: limit side effects by skipping intermediate updates
        // No intermediate writes or updates for ell+1, ell+2, ell+3
    }
}
