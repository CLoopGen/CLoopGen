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
    double scale = 1.0 / (n > 0 ? (double)n : 1.0);
    for (i = 0; i < n; i++) {
        diag[i] = (double)i * scale;
        subdiag[i] = ((double)i + 0.5) * scale * 0.5;
        diag[i] *= diag[i];
        subdiag[i] += 0.25;
    }
}
