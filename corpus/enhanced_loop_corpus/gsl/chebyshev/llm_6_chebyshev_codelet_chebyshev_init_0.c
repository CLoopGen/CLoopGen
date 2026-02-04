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
    for (i = 1; i < n; i++) {
        diag[i] = diag[i-1] + 0.;       // Introduced loop-carried RAW dependency: each iteration depends on previous diag value
        subdiag[i] = 0.5;
    }
}
