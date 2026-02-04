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
    const long cpu_freq_approx = 3000000000L; // Approximate modern CPU frequency (3 GHz)
    const long operations_per_iteration = 2; // Rough estimate: one comparison, one load
    size_t estimated_iterations = target_time_ns * cpu_freq_approx / (1e9 * operations_per_iteration);
    
    // Clamp data size between 1MB and 256MB
    len = estimated_iterations;
    if (len < 1024*1024) len = 1024*1024;
    if (len > 256*1024*1024) len = 256*1024*1024;

    internal_buffer = (char*)malloc(len + 1);
    if (!internal_buffer) {
        len = 1024*1024; // Fallback to 1MB
        internal_buffer = (char*)malloc(len + 1);
        if (!internal_buffer) exit(1);
    }

    // Fill buffer with non-zero values except at the end
    memset(internal_buffer, 'A', len);
    internal_buffer[len] = '\0'; // Null terminate so loop stops at end

    s = internal_buffer;
    i = 0;
}