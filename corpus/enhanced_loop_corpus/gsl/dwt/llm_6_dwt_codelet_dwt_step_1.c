#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double *scratch;
    size_t n;
} gsl_wavelet_workspace;

extern double *a;
extern size_t stride;
extern size_t n;
extern gsl_wavelet_workspace *work;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *local_a = a;
    size_t local_stride = stride;
    double *local_scratch = work->scratch;
    size_t local_n = n;
    for (i = 0; i < local_n; i++) {
        local_a[local_stride * i] = local_scratch[i];
    }
}
