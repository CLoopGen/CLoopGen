#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_s_buffer;

void init_vars() {
    const size_t target_time_ns = 10000000; // 0.01 seconds in nanoseconds
    const long cpu_freq_gigahertz = 3; // Approximate modern CPU frequency
    const size_t operations_per_byte = 1; // Simple load and compare per byte
    size_t data_size = target_time_ns / (cpu_freq_gigahertz * 1e9 / 1e9 * operations_per_byte);
    
    // Clamp data size between 1MB and 256MB
    data_size = data_size < (1 << 20) ? (1 << 20) : data_size;
    data_size = data_size > (256 << 20) ? (256 << 20) : data_size;

    internal_s_buffer = (char *)malloc(data_size);
    if (!internal_s_buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to ensure loop runs nearly full length
    memset(internal_s_buffer, 'x', data_size - 1);
    internal_s_buffer[data_size - 1] = '\0'; // Null terminate at end

    s = internal_s_buffer;
    len = data_size;
    i = 0;
}