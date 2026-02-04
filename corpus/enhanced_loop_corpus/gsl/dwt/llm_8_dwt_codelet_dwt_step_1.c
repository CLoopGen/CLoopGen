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
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            ((a)[(stride) * (i)]) = work->scratch[i] * 2.0;
            ((a)[(stride) * (i + 1)]) = work->scratch[i + 1] * 2.0;
        } else {
            ((a)[(stride) * (i)]) = work->scratch[i] * 2.0;
        }
    }
}
