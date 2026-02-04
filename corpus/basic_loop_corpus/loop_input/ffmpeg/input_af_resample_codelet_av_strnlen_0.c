#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_buffer;

void init_vars() {
    const size_t target_time_ns = 10000000; // 10 ms in nanoseconds
    const long cpu_freq_approx = 3000000000L; // Assume 3 GHz CPU
    const size_t operations_per_byte = 2; // Approximate ops per byte (bound by loop condition and load)
    
    size_t data_size = (target_time_ns * cpu_freq_approx) / (1000000000 * operations_per_byte);
    data_size = data_size < (1 << 20) ? (1 << 20) : data_size; // Min 1MB
    data_size = data_size > (256 << 20) ? (256 << 20) : data_size; // Max 256MB

    internal_buffer = (char *)malloc(data_size);
    if (!internal_buffer) {
        exit(1);
    }

    memset(internal_buffer, 'x', data_size - 1);
    internal_buffer[data_size - 1] = '\0';

    s = internal_buffer;
    len = data_size;
}