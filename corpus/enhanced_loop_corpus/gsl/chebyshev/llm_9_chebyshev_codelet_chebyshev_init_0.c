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
    for (i = 1; i < n; i++) {
        diag[i] = (double)(i % 2) * 0.0;
        for (j = 0; j < 3; j++) {
            subdiag[i] = subdiag[i] * 1.0 + (0.5 - subdiag[i]) / (j + 1);
        }
    }
}
