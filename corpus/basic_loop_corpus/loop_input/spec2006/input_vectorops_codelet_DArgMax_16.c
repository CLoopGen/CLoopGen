#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

double *vec;
int n = 1 << 24; // Approximately 16M elements, ~128MB of data
int i;
int best = 0;

void init_vars() {
    vec = (double*)aligned_alloc(32, n * sizeof(double));
    if (!vec) {
        exit(1);
    }
    srand(time(NULL));
    for (int j = 0; j < n; j++) {
        vec[j] = (double)rand() / RAND_MAX * 1000.0;
    }
    best = 0;
    i = 0;
}