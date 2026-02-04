#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <sys/time.h>

float *X;
int N;
int i;
float g;

void init_vars() {
    struct timeval tv_start, tv_end;
    double elapsed;
    int warmup_N = 1000000; // Start with ~4MB for warm-up timing
    float *warmup_X = (float*)malloc(warmup_N * sizeof(float));
    float warmup_g = 1.5f;
    int idx;

    // Warm up to estimate time per iteration
    for (idx = 0; idx < warmup_N; idx++) {
        warmup_X[idx] = (float)(idx % 100);
    }

    gettimeofday(&tv_start, NULL);
    for (idx = 0; idx < warmup_N; idx++) {
        warmup_X[idx] *= warmup_g;
    }
    gettimeofday(&tv_end, NULL);

    elapsed = (tv_end.tv_sec - tv_start.tv_sec) + (tv_end.tv_usec - tv_start.tv_usec) / 1e6;

    // Scale N to achieve approximately 0.01 seconds
    N = (int)((10.0 / elapsed) * warmup_N);
    // Clamp N between reasonable bounds (1MB and 256MB of float data)
    if (N < 256000) N = 256000;      // ~1MB
    else if (N > 67108864) N = 67108864; // ~256MB

    free(warmup_X);

    // Allocate X with computed size
    X = (float*)malloc(N * sizeof(float));
    if (!X) {
        N = 256000; // Fallback size
        X = (float*)malloc(N * sizeof(float));
    }

    // Initialize X and other variables
    for (i = 0; i < N; i++) {
        X[i] = (float)(i % 200);
    }
    g = 1.25f;
    i = 0;
}