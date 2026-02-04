#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

float *x;
int n;
float xx[864];

void init_vars() {
    n = 864;

    x = (float*)aligned_alloc(32, n * sizeof(float));
    if (!x) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        x[i] = (float)(i * 2.5);
        xx[i] = 0.0f;
    }
}