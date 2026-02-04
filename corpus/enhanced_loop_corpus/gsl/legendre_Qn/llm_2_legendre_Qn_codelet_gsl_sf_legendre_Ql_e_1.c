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
    // Variant 1: Strided memory access pattern (simulated via scaling index)
    // Though the variables are scalars, we simulate a strided access conceptually 
    // by introducing an effective stride through a scaled loop index.
    int stride = 2;
    for (ell = l; ell > 0; ell -= stride) {
        // Perform computation at strided iteration points
        Qellm1 = (x * (2. * ell + 1.) * Qell - (ell + 1.) * Qellp1) / ell;
        Qellp1 = Qell;
        Qell = Qellm1;
        // Ensure forward progress even with non-unit decrement
        if (ell == 1) break;
    }
}
