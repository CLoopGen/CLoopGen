#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    double r;
    double i;
} complex;

double *data;
int fftsize;
int j;
complex *IN;

void init_vars() {
    fftsize = 1 << 20;  // 1M elements, approx 8MB for data, 16MB for IN (complex)

    data = (double*)aligned_alloc(32, fftsize * sizeof(double));
    IN = (complex*)aligned_alloc(32, fftsize * sizeof(complex));

    for (int i = 0; i < fftsize; i++) {
        data[i] = (double)(i % 1000) / 10.0;
        IN[i].r = 0.0;
        IN[i].i = 0.0;
    }
}