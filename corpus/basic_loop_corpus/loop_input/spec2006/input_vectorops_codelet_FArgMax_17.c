#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

float *vec;
int n = 1 << 20; // Approximately 4MB of data (1M floats), suitable for ~0.01 sec runtime
int i = 0;
int best = 0;

void init_vars() {
    vec = (float*)aligned_alloc(32, n * sizeof(float));
    if (!vec) {
        exit(1);
    }

    // Initialize with random values to ensure meaningful comparison in loop
    srand(time(NULL));
    for (int j = 0; j < n; j++) {
        vec[j] = (float)rand() / RAND_MAX * 1000.0f;
    }

    // Ensure initial conditions: best is valid and within bounds
    best = 0;
    i = 0;
}