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
    // Target approximately 0.01 seconds runtime on modern CPU
    // For a simple loop like this, we estimate that 64MB of data
    // will take around 10ms when scanning for null byte
    size_t target_size = 64 * 1024 * 1024; // 64 MB

    internal_buffer = (char *)malloc(target_size);
    if (!internal_buffer) {
        exit(1);
    }

    // Fill most of the buffer with non-zero bytes
    memset(internal_buffer, 'A', target_size - 1);
    
    // Place null terminator near the end to ensure loop runs long enough
    internal_buffer[target_size - 1] = '\0';

    s = internal_buffer;
    len = target_size;
    i = 0;
}