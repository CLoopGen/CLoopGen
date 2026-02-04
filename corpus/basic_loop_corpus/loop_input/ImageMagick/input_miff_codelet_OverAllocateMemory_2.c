#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

size_t length;
size_t extent;

static size_t get_suitable_length() {
    struct timeval start, end;
    size_t test_length = 1 << 20; // Start with 1MB
    size_t max_length = 256 << 20; // Cap at 256MB
    double elapsed = 0.0;

    while (test_length <= max_length && elapsed < 0.005) {
        length = test_length;
        gettimeofday(&start, NULL);
        for (extent = 256; extent < length; extent *= 2) {
            // Simulate minimal work to time the loop
            __asm__ volatile("" : : : "memory");
        }
        gettimeofday(&end, NULL);
        elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
        if (elapsed < 0.005) {
            test_length *= 2;
        } else {
            break;
        }
    }
    return test_length > max_length ? max_length : test_length;
}

void init_vars() {
    length = get_suitable_length();
    extent = 0;
}