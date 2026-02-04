#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t lmax;
extern  double csfac;
extern double *cl;
extern double *dl;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This variant accesses every second element, assuming lmax is even for simplicity
    for (l = 2; l <= lmax; l += 2) {
        cl[l] = 2. * l + 1.;
        dl[l] = csfac * (2. * l - 1.);
    }
    // Handle odd indices if lmax is odd
    for (l = 3; l <= lmax; l += 2) {
        cl[l] = 2. * l + 1.;
        dl[l] = csfac * (2. * l - 1.);
    }
}
