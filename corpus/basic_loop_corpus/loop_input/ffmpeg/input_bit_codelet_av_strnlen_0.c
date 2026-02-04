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
    size_t target_time_ns = 10000000; // 0.01 seconds in nanoseconds
    double cycles_per_byte_estimate = 1.0;
    size_t buffer_size = (size_t)(target_time_ns / cycles_per_byte_estimate);
    
    if (buffer_size < (1 << 20)) buffer_size = (1 << 20); 
    if (buffer_size > (256 << 20)) buffer_size = (256 << 20);

    internal_buffer = (char *)malloc(buffer_size);
    if (!internal_buffer) {
        exit(1);
    }

    for (size_t j = 0; j < buffer_size - 1; j++) {
        internal_buffer[j] = 'x';
    }
    internal_buffer[buffer_size - 1] = '\0';

    s = internal_buffer;
    len = buffer_size - 1;
    i = 0;
}