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
    double *scratch = work->scratch;
    size_t n = work->n;
    if (n > 0) {
        scratch[0] = 0.;
        for (i = 1; i < n; i++) {
            scratch[i] = scratch[i-1]; // Introduce RAW dependency: each write depends on previous value
        }
        // Final pass to ensure all are 0., resolving the carried dependency
        for (i = 0; i < n; i++) {
            scratch[i] = 0.;
        }
    }
}
