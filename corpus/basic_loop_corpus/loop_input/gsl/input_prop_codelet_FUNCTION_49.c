#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

static double get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec * 1e-9;
}

void init_vars() {
    const double target_duration = 0.01;
    double start_time, end_time;
    size_t temp_size1, temp_size2;
    size_t base_size1 = 1000;
    size_t base_size2 = 1000;

    size1 = base_size1;
    size2 = base_size2;

    start_time = get_time();
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
        }
    }
    end_time = get_time();

    double elapsed = end_time - start_time;
    if (elapsed > 0) {
        double factor = target_duration / elapsed;
        temp_size1 = (size_t)(base_size1 * factor);
        temp_size2 = base_size2;

        size1 = (temp_size1 > 100) ? temp_size1 : 100;
        size2 = base_size2;
    } else {
        size1 = 50000;
        size2 = 5000;
    }

    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
        }
    }
}