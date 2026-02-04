#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    double r;
    double i;
} complex;

int fftsize;
int j;
complex *IN;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; 
    const size_t bytes_per_complex = sizeof(complex);
    fftsize = target_bytes / bytes_per_complex;

    IN = (complex*)aligned_alloc(32, fftsize * sizeof(complex));
    if (!IN) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < fftsize; i++) {
        IN[i].r = 1.0;
        IN[i].i = 1.0;
    }

    j = 0;
}