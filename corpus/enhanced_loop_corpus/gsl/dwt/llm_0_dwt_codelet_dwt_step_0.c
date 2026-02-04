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
    for (size_t outer = 0; outer < work->n; outer++) {
        for (size_t inner = 0; inner < 1; inner++) {
            work->scratch[outer] = 0.;
        }
    }
}
