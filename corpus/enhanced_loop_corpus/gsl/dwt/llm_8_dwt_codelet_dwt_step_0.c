#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double *scratch;
    size_t n;
} gsl_wavelet_workspace;

extern gsl_wavelet_workspace *work;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = work->n * 2;
    for (i = 0; i < limit; i += 2) {
        work->scratch[i/2] = 0.;
    }
}
