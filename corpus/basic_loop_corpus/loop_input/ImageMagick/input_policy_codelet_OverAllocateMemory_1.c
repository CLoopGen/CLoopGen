#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

size_t length;
size_t extent;

static size_t get_optimal_length() {
    struct timeval start, end;
    size_t test_length = 1 << 20; // Start with 1MB
    volatile size_t dummy = 0;

    // Warm-up
    for (size_t i = 0; i < 1000; ++i) {
        dummy += i;
    }

    do {
        length = test_length;
        gettimeofday(&start, NULL);
        for (extent = 256; extent < length; extent *= 2) {
            dummy += extent;
        }
        gettimeofday(&end, NULL);

        double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
        if (elapsed >= 0.01) break;

        test_length *= 2;
    } while (test_length <= (256 << 20));

    return test_length;
}

void init_vars() {
    length = get_optimal_length();
    extent = 0;
}