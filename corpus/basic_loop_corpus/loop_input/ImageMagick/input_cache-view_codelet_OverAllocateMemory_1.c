#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

size_t length;
size_t extent;

static double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

void init_vars() {
    const double target_time = 0.01;
    double start_time, end_time;
    size_t temp_length;
    size_t test_extent;

    for (temp_length = 1 << 20; temp_length <= (256 << 20); temp_length <<= 1) {
        length = temp_length;
        test_extent = 256;
        start_time = get_time();
        while (test_extent < length) {
            test_extent *= 2;
        }
        end_time = get_time();
        if (end_time - start_time >= target_time * 0.9) {
            break;
        }
    }

    length = temp_length;
    extent = 256;
}