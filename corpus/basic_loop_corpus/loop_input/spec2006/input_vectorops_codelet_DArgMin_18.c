#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

double *vec;
int n = 32000000;  // Approximately 256 MB of data (32M * 8 bytes per double)
int i;
int best;

void init_vars() {
    vec = (double*)malloc(n * sizeof(double));
    if (!vec) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (int j = 0; j < n; j++) {
        vec[j] = (double)(rand() % 10000) + (double)(rand() % 1000) / 1000.0;
    }
    best = 0;
    i = 0;
}