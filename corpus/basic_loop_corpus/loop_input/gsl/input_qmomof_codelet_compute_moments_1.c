#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *chebmo;
double v[28];
size_t i;

void init_vars() {
    const size_t chebmo_size = 256 * (1 << 20) / sizeof(double); // ~256MB
    double *chebmo_data = (double *)calloc(chebmo_size, sizeof(double));
    chebmo = chebmo_data;

    for (int j = 0; j < 28; j++) {
        v[j] = (double)(j + 1) * 1.5;
    }
}