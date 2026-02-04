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
    const size_t target_time_ns = 10000000; // 0.01 seconds in nanoseconds
    const long double cpu_freq_ghz = 3.0; // Assume 3 GHz for estimation
    const uint64_t ops_per_byte = 2; // Rough estimate of operations per byte

    // Calculate data size: time * freq / work_per_byte
    size_t data_size = (size_t)((target_time_ns / 1e9) * cpu_freq_ghz * 1e9 / ops_per_byte);
    data_size = data_size < (1 << 20) ? (1 << 20) : data_size; // At least 1MB
    data_size = data_size > (256 << 20) ? (256 << 20) : data_size; // Max 256MB

    buffer = (char *)aligned_alloc(64, data_size);
    if (!buffer) {
        exit(1);
    }

    // Initialize with non-null bytes
    memset(buffer, 'x', data_size - 1);
    // Place null terminator near the end to ensure loop runs long but terminates
    buffer[data_size - 1] = '\0';

    s = buffer;
    len = data_size;
    i = 0;
}