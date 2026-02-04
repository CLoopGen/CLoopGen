#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float (*x)[2];
int n;
float sum0;
float sum1;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of float data (each float is 4 bytes, two per inner array)
    n = data_size / (2 * sizeof(float));       // Each element is a [2] array of floats
    x = aligned_alloc(32, n * sizeof(*x));
    
    if (!x) {
        exit(1);
    }

    for (int idx = 0; idx < n; idx++) {
        x[idx][0] = 1.0f + idx * 0.0001f;
        x[idx][1] = 1.5f + idx * 0.0001f;
    }

    sum0 = 0.0f;
    sum1 = 0.0f;
    i = 0;
}