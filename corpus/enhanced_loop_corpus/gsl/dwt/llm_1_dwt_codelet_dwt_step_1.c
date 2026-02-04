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
    if (n > 0) {
        for (i = 0; i < n; i += 2) {
            ((a)[(stride) * (i)]) = work->scratch[i];
            if (i + 1 < n) {
                ((a)[(stride) * (i + 1)]) = work->scratch[i + 1];
            }
        }
    }
}
