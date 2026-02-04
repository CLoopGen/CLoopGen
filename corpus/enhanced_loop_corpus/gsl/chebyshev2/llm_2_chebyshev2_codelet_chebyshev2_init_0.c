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
    for (i = 0; i < n; i += 2) {
        if (i < n) {
            diag[i] = 0.;
            subdiag[i] = 0.5;
        }
        if (i + 1 < n) {
            diag[i + 1] = 0.;
            subdiag[i + 1] = 0.5;
        }
    }
}
