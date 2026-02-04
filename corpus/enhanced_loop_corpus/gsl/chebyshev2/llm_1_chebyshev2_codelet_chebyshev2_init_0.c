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
    if (n > 0) {
        for (i = 0; i < n; i += 2) {
            diag[i] = 0.;
            subdiag[i] = 0.5;
            if (i + 1 < n) {
                diag[i + 1] = 0.;
                subdiag[i + 1] = 0.5;
            }
        }
    }
}
