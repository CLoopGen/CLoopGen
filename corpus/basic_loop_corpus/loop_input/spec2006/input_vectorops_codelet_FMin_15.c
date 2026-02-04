#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

float *vec;
int n = 1 << 20; // Approximately 4MB of data (1M floats), adjust for ~0.01s runtime
int i;
float best;

void init_vars() {
    vec = (float*)aligned_alloc(32, n * sizeof(float));
    if (!vec) {
        exit(1);
    }

    // Initialize with random values, ensure first element is not the smallest
    srand((unsigned int)time(NULL));
    vec[0] = 1000.0f;
    best = vec[0];

    for (int j = 1; j < n; j++) {
        vec[j] = (rand() % 2000) * 0.1f;
        if (vec[j] < best) {
            best = vec[j]; // This simulates what loop() would do, but we reset below
        }
    }

    // Reset best to a value that will be updated in the loop
    best = vec[0];
}