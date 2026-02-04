#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

double *sample_noise;
double temp[15];

void init_vars() {
    sample_noise = (double*)aligned_alloc(32, 15 * sizeof(double));
    if (!sample_noise) {
        exit(1);
    }
    for (int i = 0; i < 15; i++) {
        sample_noise[i] = sin(i * 0.7) * cos(i * 1.3);
    }
}