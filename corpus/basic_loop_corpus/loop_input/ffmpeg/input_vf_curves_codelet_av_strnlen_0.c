#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    const size_t target_time_us = 10000; // 0.01 seconds in microseconds
    const long long cpu_freq_mhz = 2500; // Assume 2.5 GHz CPU for estimation
    const long long operations_per_cycle = 1; // Rough estimate for loop overhead

    // Estimated iterations to reach ~0.01s
    long long estimated_iters = cpu_freq_mhz * target_time_us / operations_per_cycle;

    // Clamp between 1MB and 256MB
    size_t data_size = (size_t)(estimated_iters);
    if (data_size < 1024*1024) data_size = 1024*1024;
    else if (data_size > 256*1024*1024) data_size = 256*1024*1024;

    buffer = (char*)calloc(data_size, sizeof(char));
    if (!buffer) {
        exit(1);
    }

    // Fill with non-zero up to near the end, null-terminate at the end
    memset(buffer, 'A', data_size - 1);
    buffer[data_size - 1] = '\0';

    s = buffer;
    len = data_size;
    i = 0;
}