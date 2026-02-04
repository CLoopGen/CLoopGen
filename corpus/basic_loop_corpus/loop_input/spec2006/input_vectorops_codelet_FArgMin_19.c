#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

float *vec;
int n = 67108864; // ~256MB of float data (67M elements)
int i;
int best;

void init_vars() {
    vec = (float*)aligned_alloc(32, n * sizeof(float));
    if (!vec) {
        exit(1);
    }

    // Initialize with random values to ensure meaningful comparisons
    srand(time(NULL));
    for (int j = 0; j < n; j++) {
        vec[j] = (float)rand() / RAND_MAX * 1000.0f;
    }

    // Ensure initial best is valid and within bounds
    best = 0;
    i = 0;
}