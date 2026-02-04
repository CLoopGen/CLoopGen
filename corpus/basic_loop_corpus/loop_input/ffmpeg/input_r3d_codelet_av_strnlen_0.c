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
    const long cpu_freq_approx = 3000000000L; // Approximate modern CPU frequency (3 GHz)
    const size_t operations_per_byte = 1; // Simple memory load per byte
    size_t data_size = target_time_ns * cpu_freq_approx / (1e9 * operations_per_byte);
    
    // Clamp data size between 1MB and 256MB
    if (data_size < 1024*1024) data_size = 1024*1024;
    if (data_size > 256*1024*1024) data_size = 256*1024*1024;

    buffer = (char*)malloc(data_size);
    if (!buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to simulate string without early null
    memset(buffer, 'x', data_size - 1);
    buffer[data_size - 1] = '\0'; // Null terminate at end

    s = buffer;
    len = data_size;
    i = 0;
}