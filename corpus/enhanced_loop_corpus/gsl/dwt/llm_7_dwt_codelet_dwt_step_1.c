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
    double *local_scratch = work->scratch;
    for (i = 0; i < n; i++) {
        a[stride * i] = local_scratch[i] + a[stride * (i > 0 ? i - 1 : 0)];
    }
}
