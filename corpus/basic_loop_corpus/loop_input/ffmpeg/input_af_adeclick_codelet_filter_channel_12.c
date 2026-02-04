#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(double))

double *is;
double *dst;
int j;
double *interpolated;
int *_usr_index;
int nb_errors;
double *enabled;

void init_vars() {
    nb_errors = TOTAL_ELEMENTS;

    is = (double *)calloc(nb_errors, sizeof(double));
    dst = (double *)calloc(nb_errors, sizeof(double));
    interpolated = (double *)malloc(nb_errors * sizeof(double));
    _usr_index = (int *)malloc(nb_errors * sizeof(int));
    enabled = (double *)malloc(nb_errors * sizeof(double));

    if (!is || !dst || !interpolated || !_usr_index || !enabled) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < nb_errors; i++) {
        interpolated[i] = (double)(i + 1) * 0.5;
        _usr_index[i] = rand() % nb_errors;
        enabled[i] = (rand() % 2) ? 1.0 : 0.0;
    }
}