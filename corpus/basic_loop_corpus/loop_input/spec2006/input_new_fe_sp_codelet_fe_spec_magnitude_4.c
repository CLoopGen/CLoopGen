#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
    double r;
    double i;
} complex;

double *spec;
int fftsize;
int j;
complex *FFT;

void init_vars() {
    fftsize = 1 << 20;  // Approximately 1M elements, leads to ~0.01 sec runtime

    spec = (double *)calloc(fftsize / 2 + 1, sizeof(double));
    FFT = (complex *)calloc(fftsize / 2 + 1, sizeof(complex));

    for (int idx = 0; idx <= fftsize / 2; idx++) {
        FFT[idx].r = (double)(idx % 100) / 10.0;
        FFT[idx].i = (double)((idx + 10) % 100) / 15.0;
    }
}