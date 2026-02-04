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
        if (i % 2 == 0) {
            diag[i] = 0.;
        } else {
            diag[i] = 0.;
            subdiag[i] = 0.5;
        }
    }
}
