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
    size_t j;
    for (i = 0; i < n; i++) {
        j = i + 1;
        if (j < n) {
            diag[j] = diag[i] + 0.1;        
            subdiag[i] = 0.5;
        } else {
            diag[i] = 0.;
            subdiag[i] = 0.5;
        }
    }
}
