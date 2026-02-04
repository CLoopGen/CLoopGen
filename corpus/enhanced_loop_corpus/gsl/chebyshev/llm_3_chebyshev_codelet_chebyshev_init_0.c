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
    // Variant 2: Reverse order traversal (consecutive but backward)
    // Alters memory access pattern by iterating from n-1 down to 1
    for (i = n - 1; i >= 1; i--) {
        diag[i] = 0.;
        subdiag[i] = 0.5;
    }
}
