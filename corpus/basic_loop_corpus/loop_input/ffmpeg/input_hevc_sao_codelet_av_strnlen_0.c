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
    const long cpu_freq_approx = 2500000000L; // Approximate CPU frequency (2.5 GHz)
    const double iterations_per_byte = 1.0; // Rough estimate for loop overhead

    // Estimate data size to achieve ~10ms runtime
    size_t estimated_bytes = (target_time_ns * cpu_freq_approx) / (1000000000.0 * iterations_per_byte);
    len = (estimated_bytes < (1<<20)) ? (1<<20) : estimated_bytes; // Cap min at 1MB
    if (len > (256<<20)) len = 256<<20; // Cap max at 256MB

    internal_buffer = malloc(len + 1);
    if (!internal_buffer) {
        fprintf(stderr, "Failed to allocate buffer\n");
        exit(1);
    }

    s = internal_buffer;

    // Fill buffer with non-zero bytes to prevent early termination
    memset(internal_buffer, 'x', len);
    internal_buffer[len] = '\0'; // Ensure loop terminates at end
}