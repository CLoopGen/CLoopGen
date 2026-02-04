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
    // Variant 2: Reverse order (consecutive but backward) memory access
    for (i = n; i > 0; --i) {
        size_t idx = i - 1;
        diag[idx] = 0.;
        subdiag[idx] = 0.5;
    }
}
