#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

float *Y;
int N;
int i;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    N = 1 << 20; // 1 million elements
    Y = (float *)aligned_alloc(32, N * sizeof(float));
    if (!Y) {
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        Y[j] = (float)(j % 1000);
    }

    // Warm-up loop to estimate timing
    for (int iter = 0; iter < 10; iter++) {
        for (i = 0; i < N; i++) {
            Y[i] *= -1;
        }
    }

    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    double target_time = 0.01;
    double scale = target_time / (elapsed / 10.0);

    int new_N = (int)(N * scale);
    if (new_N > 0 && new_N <= (1U << 28)) {
        N = new_N;
    } else {
        N = 1 << 20; // fallback
    }

    free(Y);
    Y = (float *)aligned_alloc(32, N * sizeof(float));
    if (!Y) {
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        Y[j] = (float)(j % 1000);
    }
}