#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

size_t Kevents;
size_t k;
size_t nBigs;
size_t nSmalls;
double *E;
double mean;
size_t *which;

void init_vars() {
    // Estimate data size for ~0.01 seconds runtime
    // Assume modern CPU can do ~1e9 operations/sec -> target ~1e7 iterations
    Kevents = 10000000;  // 10 million elements

    // Allocate arrays
    E = (double*)aligned_alloc(32, Kevents * sizeof(double));
    which = (size_t*)aligned_alloc(32, Kevents * sizeof(size_t));

    // Initialize scalar variables
    nBigs = 0;
    nSmalls = 0;
    mean = 0.5;

    // Seed random number generator and initialize E with random values in [0, 1)
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < Kevents; ++i) {
        E[i] = rand() / (double)(RAND_MAX + 1.0);
    }
}