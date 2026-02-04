#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

size_t K;
size_t i;
size_t j;

void init_vars() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    K = 1;

    while (1) {
        i = 0;
        for (i = 0; i < K; i++) {
            for (j = 0; j < i; j++) {
            }
        }

        clock_gettime(CLOCK_MONOTONIC, &end);
        double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

        if (elapsed >= 0.01) break;

        K = (K < 10000) ? K * 2 : K + 5000;
    }
}