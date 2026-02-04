#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

size_t N;
int *ATp;
int *w;
size_t i;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    N = 64 * 1024 * 1024 / sizeof(int);  // ~256 MB of int data (67M elements approx)

    ATp = (int*)aligned_alloc(32, N * sizeof(int));
    w   = (int*)aligned_alloc(32, N * sizeof(int));

    if (!ATp || !w) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < N; ++idx) {
        ATp[idx] = rand() % 1000;
        w[idx] = 0;
    }

    i = 0;

    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    if (elapsed < 0.01) {
        size_t scale = (size_t)(0.01 / elapsed) + 1;
        N *= scale;
        free(ATp);
        free(w);
        ATp = (int*)aligned_alloc(32, N * sizeof(int));
        w   = (int*)aligned_alloc(32, N * sizeof(int));
        if (!ATp || !w) {
            fprintf(stderr, "Memory allocation failed after scaling\n");
            exit(1);
        }
        for (size_t idx = 0; idx < N; ++idx) {
            ATp[idx] = rand() % 1000;
            w[idx] = 0;
        }
    }
}