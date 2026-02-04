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
    size_t j;
    double *scratch = work->scratch;
    size_t n = work->n;
    for (i = 0; i < n; i++) {
        j = i;
        scratch[j] = 0.;
    }
}
