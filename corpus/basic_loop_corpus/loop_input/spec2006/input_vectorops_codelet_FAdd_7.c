#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

float *vec1;
float *vec2;
int n;
int x;

void init_vars() {
    n = 67108864; // Approximately 256MB of data (67M * 4 bytes per float * 2 arrays)

    vec1 = (float*)aligned_alloc(32, n * sizeof(float));
    vec2 = (float*)aligned_alloc(32, n * sizeof(float));

    if (!vec1 || !vec2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        vec1[i] = (float)(rand()) / RAND_MAX;
        vec2[i] = (float)(rand()) / RAND_MAX;
    }
}