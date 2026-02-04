#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern double *diag;
extern double *subdiag;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This variant processes every second element in two passes to cover all indices
    for (i = 1; i < n; i += 2) {
        diag[i] = 0.;
        subdiag[i] = 0.5;
    }
    for (i = 2; i < n; i += 2) {
        diag[i] = 0.;
        subdiag[i] = 0.5;
    }
}
