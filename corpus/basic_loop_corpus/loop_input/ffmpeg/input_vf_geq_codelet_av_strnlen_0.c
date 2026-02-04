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
    const size_t target_time_ns = 10000000; // 10 ms in nanoseconds
    const long double cpu_freq_ghz = 3.0; // Assume 3 GHz for estimation
    const uint64_t ops_per_byte = 2; // Rough estimate of operations per byte

    // Calculate data size based on estimated execution time
    size_t data_size = (target_time_ns / (cpu_freq_ghz * 1e9)) * cpu_freq_ghz * 1e9 / ops_per_byte;
    data_size = data_size < (1 << 20) ? (1 << 20) : data_size; // Min 1MB
    data_size = data_size > (256 << 20) ? (256 << 20) : data_size; // Max 256MB

    internal_s_buffer = (char*)malloc(data_size);
    if (!internal_s_buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to ensure loop runs through most of the buffer
    memset(internal_s_buffer, 'A', data_size - 1);
    internal_s_buffer[data_size - 1] = '\0'; // Null terminate at end

    s = internal_s_buffer;
    len = data_size;
    i = 0;
}