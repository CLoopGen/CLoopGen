#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *lut;
int N;
int n;
double b;
double sum;
double t;
double c;
double norm;
int j;

void init_vars() {
    N = 1 << 20; // Approximately 1M elements to fit ~4MB array (assuming float is 4 bytes)
    lut = (float*)aligned_alloc(32, N * sizeof(float));
    if (!lut) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize all scalar variables to ensure defined behavior
    b = 2.0;
    sum = 0.0;
    t = 0.0;
    c = 0.0;
    norm = 0.0;
    j = 0;
    n = 0;

    // Ensure that the loop bounds are safe: indices n and N-1-n must be in [0, N-1]
    // With N = 1<<20, and n starting at (N-1)/2, we are well within bounds.
}