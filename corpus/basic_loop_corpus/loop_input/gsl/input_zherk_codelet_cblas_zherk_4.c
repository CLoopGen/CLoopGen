#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

int N;
void *C;
int ldc;
int i;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    ldc = 1024;
    N = 0;
    int max_n = 65536;
    C = aligned_alloc(32, ldc * max_n * sizeof(double) + 32);

    if (!C) exit(1);

    double *C_d = (double *)C;
    for (N = 1; N <= max_n; N++) {
        int idx = 2 * (ldc * (N-1) + (N-1)) + 1;
        if (idx >= (int)((ldc * max_n * sizeof(double)) / sizeof(double))) break;
        C_d[idx] = 0.0;
    }
    N--;

    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

    while (elapsed < 0.01) {
        N = (N < max_n) ? N + 1 : max_n;
        for (int i = 0; i < N; i++) {
            (((double *)C)[2 * (ldc * i + i) + 1]) = 0.;
        }
        gettimeofday(&start, NULL);
        for (volatile int j = 0; j < N; j++) {
            volatile double x = ((double *)C)[2 * (ldc * j + j) + 1];
        }
        gettimeofday(&end, NULL);
        elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    }

    for (int i = 0; i < N; i++) {
        int idx = 2 * (ldc * i + i) + 1;
        if (idx >= ldc * max_n * 2) {
            N = i;
            break;
        }
    }
}