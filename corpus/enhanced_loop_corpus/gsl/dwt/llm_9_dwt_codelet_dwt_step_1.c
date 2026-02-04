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
    size_t j;
    for (i = 0; i < n; i++) {
        double temp = work->scratch[i];
        for (j = 0; j < 3; j++) {
            temp = temp * temp + 1e-6; 
        }
        ((a)[(stride) * (i)]) = temp;
    }
}
