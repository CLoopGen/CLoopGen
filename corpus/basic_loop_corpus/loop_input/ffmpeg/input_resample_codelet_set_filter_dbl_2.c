#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *tab;
int tap_count;
int i;
double *filter;

void init_vars() {
    tap_count = 16777216; // Approximately 128 MB of data (16M * 8 bytes per double)

    tab = (double *)aligned_alloc(32, tap_count * sizeof(double));
    filter = (double *)aligned_alloc(32, tap_count * sizeof(double));

    for (i = 0; i < tap_count; i++) {
        tab[i] = (double)(i % 1000) / 100.0;
    }

    for (i = 0; i < tap_count; i++) {
        filter[i] = 0.0;
    }
}