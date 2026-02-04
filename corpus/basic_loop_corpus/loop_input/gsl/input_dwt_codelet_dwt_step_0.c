#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double *scratch;
    size_t n;
} gsl_wavelet_workspace;

gsl_wavelet_workspace *work;
size_t i;

static double *scratch_data;
static size_t data_size = 16777216; // ~128 MB of doubles (16M elements)

void init_vars() {
    scratch_data = (double *)calloc(data_size, sizeof(double));
    if (!scratch_data) {
        exit(1);
    }

    work = (gsl_wavelet_workspace *)malloc(sizeof(gsl_wavelet_workspace));
    if (!work) {
        exit(1);
    }

    work->scratch = scratch_data;
    work->n = data_size;
    i = 0;
}