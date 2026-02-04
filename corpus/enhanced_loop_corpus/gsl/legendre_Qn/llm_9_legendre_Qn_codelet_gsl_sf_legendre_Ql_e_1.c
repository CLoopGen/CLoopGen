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
    // Variant 2: Reduced trip count and simplified computation to lower computational intensity
    int step = 2;
    for (ell = l; ell > 0; ell -= step) {
        // Perform one iteration of original computation, skipping every other value
        Qellm1 = (x * (2. * ell + 1.) * Qell - (ell + 1.) * Qellp1) / ell;
        Qellp1 = Qell;
        Qell = Qellm1;
        // Skip next iteration index explicitly to reduce loop iterations by ~half
        if (ell == 1) break;
    }
}
