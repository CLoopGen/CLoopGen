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
    N = 1 << 20;  // Approximately 1 million elements for ~0.01 sec runtime
    lut = (float*)aligned_alloc(32, N * sizeof(float));
    if (!lut) {
        exit(1);
    }
    
    // Initialize all scalar variables to safe values
    n = 0;
    b = 2.0;
    sum = 0.0;
    t = 0.0;
    c = 0.0;
    norm = 0.0;
    j = 0;
    
    // Pre-initialize lut array to zero to avoid undefined behavior
    for (int i = 0; i < N; ++i) {
        lut[i] = 0.0f;
    }
}