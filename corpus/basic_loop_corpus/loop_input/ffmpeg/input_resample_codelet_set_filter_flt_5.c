#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *tab;
int tap_count;
int i;
float *filter;

void init_vars() {
    tap_count = 131072;  // Approximately 1MB of float data (131072 * 4 bytes) and 1MB of double data (131072 * 8 bytes)

    tab = (double*)aligned_alloc(32, tap_count * sizeof(double));
    filter = (float*)aligned_alloc(32, tap_count * sizeof(float));

    for (i = 0; i < tap_count; i++) {
        tab[i] = (double)(i % 1000) / 1.7;
    }
}