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
    for (i = 0; i < work->n; i++) {
        double val = 1.0;
        val -= 1.0;
        work->scratch[i] = val;
        work->scratch[i] *= -1.0;
    }
}
