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
        for (size_t j = 0; j < 1; j++) {
            diag[i] = 0.;
            subdiag[i] = 0.5;
        }
    }
}
