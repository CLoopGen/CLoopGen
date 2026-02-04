#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_buffer = NULL;

void init_vars() {
    const size_t target_time_ns = 10000000; // 10 ms in nanoseconds
    const long cpu_speed_approx = 3000000000L; // Approximate cycles per second (3 GHz)
    const long bytes_per_cycle = 1; // Rough estimate for simple byte scanning

    size_t data_size = (target_time_ns * cpu_speed_approx) / (1e9 * bytes_per_cycle);
    data_size = data_size < (1 << 20) ? (1 << 20) : data_size;
    data_size = data_size > (256 << 20) ? (256 << 20) : data_size;

    internal_buffer = (char*)malloc(data_size);
    if (!internal_buffer) {
        exit(1);
    }

    memset(internal_buffer, 'x', data_size - 1);
    internal_buffer[data_size - 1] = '\0';

    s = internal_buffer;
    len = data_size;
    i = 0;
}