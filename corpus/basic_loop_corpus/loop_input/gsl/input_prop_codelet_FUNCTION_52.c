#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/time.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

static double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

void init_vars() {
    double start = get_time();

    const size_t target_ns = 10000000; // 0.01 seconds in nanoseconds
    size1 = 10000;
    size2 = 10000;

    // Warm-up run
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
        }
    }

    // Measure time with current sizes
    start = get_time();
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
        }
    }
    double elapsed = get_time() - start;

    // Scale sizes to achieve approximately 0.01 seconds
    double target = 0.01;
    if (elapsed > 0) {
        double scale = target / elapsed;
        size1 = (size_t)(size1 * scale);
        size2 = (size_t)(size2 * scale);

        // Clamp to reasonable bounds if needed
        if (size1 == 0) size1 = 1;
        if (size2 == 0) size2 = 1;
    } else {
        // Fallback if timing was too fast to measure
        size1 = 50000;
        size2 = 400;
    }

    // Final measurement to ensure we are close to target
    start = get_time();
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
        }
    }
    elapsed = get_time() - start;

    // If still too fast, increase size significantly
    if (elapsed < 0.005) {
        size1 *= 5;
        size2 *= 5;
    }
}