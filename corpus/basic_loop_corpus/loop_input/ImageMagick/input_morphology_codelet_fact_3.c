#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

size_t n;
size_t f;
size_t l;

void init_vars() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    size_t temp_n = 1;
    while (1) {
        n = temp_n;
        f = 1;
        l = 2;
        for (; l <= n; f = f * l, l++) {
            if (f > SIZE_MAX / (l + 1)) break;
        }

        clock_gettime(CLOCK_MONOTONIC, &end);
        long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
        if (elapsed_ns >= 10000000) break;
        temp_n += 1;
    }

    n = temp_n;
    f = 1;
    l = 2;
}