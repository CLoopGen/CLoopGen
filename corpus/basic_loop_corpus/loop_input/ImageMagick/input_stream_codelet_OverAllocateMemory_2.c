#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

size_t length;
size_t extent;

static size_t calculate_optimal_length() {
    struct timeval start, end;
    size_t test_length = 1 << 20; // Start with 1MB
    volatile size_t dummy = 0;

    while (test_length <= (256 << 20)) { // Up to 256MB
        length = test_length;
        gettimeofday(&start, NULL);

        for (extent = 256; extent < length; extent *= 2) {
            dummy++; // Prevent complete optimization
        }

        gettimeofday(&end, NULL);
        long elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

        if (elapsed >= 10000) { // Target ~0.01 seconds
            return test_length;
        }

        test_length += (1 << 20); // Increase by 1MB
    }

    return 256 << 20; // Default to 256MB if needed
}

void init_vars() {
    length = calculate_optimal_length();
    extent = 0;
}