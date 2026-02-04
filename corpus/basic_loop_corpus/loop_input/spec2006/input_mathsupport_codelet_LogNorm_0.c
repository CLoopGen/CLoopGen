#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

float *vec;
int n;
int x;
float max;

void init_vars() {
    n = 64 * 1024 * 1024 / sizeof(float);  // ~256 MB of data
    vec = (float *)aligned_alloc(32, n * sizeof(float));
    if (!vec) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        vec[i] = (float)(rand()) / RAND_MAX * 1000.0f;
    }

    x = 0;
    max = -__FLT_MAX__;
}

__attribute__((destructor))
void cleanup() {
    if (vec) {
        free(vec);
    }
}