#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

int N;
void *X;
int incX;
void *Y;
int incY;
int i;
int ix;
int iy;

static float *X_data;
static float *Y_data;

void init_vars() {
    const long target_time_us = 10000; // 0.01 seconds in microseconds
    const double perf_estimate = 1e9; // Assume ~1e9 operations per second (conservative)
    const double bytes_per_iter = 16; // 2 floats read, 2 written
    const double iters_per_sec = perf_estimate / 4.0; // Rough estimate of loop iterations per second
    const double estimated_N = target_time_us * 1e-6 * iters_per_sec;
    
    // Clamp N to reasonable range: at least 1000, up to 64M
    N = (int)(estimated_N < 1000 ? 1000 : 
              estimated_N > 67108864 ? 67108864 : estimated_N);
    
    // Ensure N is positive and even for safety
    if (N <= 0) N = 1000;

    // Allocate X and Y as arrays of float pairs (complex-like)
    X_data = (float*)aligned_alloc(32, 2 * N * sizeof(float));
    Y_data = (float*)aligned_alloc(32, 2 * N * sizeof(float));
    
    if (!X_data || !Y_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data with non-zero values
    for (int j = 0; j < 2 * N; j++) {
        X_data[j] = (float)(j * 0.5f + 1.0f);
        Y_data[j] = 0.0f;
    }

    X = (void*)X_data;
    Y = (void*)Y_data;

    // Set stride parameters
    incX = 1; // default forward by one element per iteration
    incY = 1;

    // Initialize loop indices
    ix = 0;
    iy = 0;

    // Ensure that the loop will not overflow: i < N guarantees 2*(ix) < 2*N
}