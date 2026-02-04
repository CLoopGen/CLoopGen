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
    size_t stride = 2;
    for (i = 0; i < work->n; i += stride) {
        if (i < work->n) work->scratch[i] = 0.;
        size_t j = i + 1;
        if (j < work->n) work->scratch[j] = 0.;
    }
}
