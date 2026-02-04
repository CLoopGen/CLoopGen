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
    for (i = 1; i < n; i += 2) {
        if (i + 1 < n) {
            diag[i] = 0.;
            diag[i + 1] = 0.;
            subdiag[i] = 0.5;
            subdiag[i + 1] = 0.5;
        } else {
            diag[i] = 0.;
            subdiag[i] = 0.5;
        }
    }
}
