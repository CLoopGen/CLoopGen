#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *h;
int n;

void init_vars() {
    n = 67108864; // Approximately 256MB for float array (67M elements)
    h = (float*)aligned_alloc(32, n * sizeof(float));
    if (!h) {
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        h[i] = (float)(i % 1000) / 3.33f;
    }
}