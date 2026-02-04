#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *chebmo;
double v[28];
size_t i;

void init_vars() {
    const size_t chebmo_size = 26; 
    double *temp_chebmo = (double *)calloc(chebmo_size, sizeof(double));
    chebmo = temp_chebmo;

    for (int j = 0; j < 28; j++) {
        v[j] = (double)(j + 1) * 1.5;
    }
}