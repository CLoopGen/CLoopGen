#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t i;
size_t m;

static double *data_ptr;
static size_t data_size;

void init_vars() {
    const double target_time = 0.01;
    const double ops_per_byte = 1.0;
    const double estimated_bandwidth_gbps = 20.0 * 1e9 / 8.0;
    size_t temp_m = (size_t)(target_time * estimated_bandwidth_gbps / ops_per_byte);
    temp_m = (temp_m + 63) & ~((size_t)63);

    if (temp_m < 100000) temp_m = 100000;
    if (temp_m > 256 * 1024 * 1024) temp_m = 256 * 1024 * 1024;

    data_size = temp_m * sizeof(double);
    data_ptr = aligned_alloc(64, data_size);
    if (!data_ptr) {
        data_size = 100000 * sizeof(double);
        data_ptr = aligned_alloc(64, data_size);
        if (!data_ptr) exit(1);
    }

    memset(data_ptr, 0, data_size);

    m = temp_m;
}

__attribute__((constructor))
void auto_init() {
    init_vars();
}

__attribute__((destructor))
void cleanup() {
    if (data_ptr) {
        free(data_ptr);
    }
}