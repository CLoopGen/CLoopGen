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
    len = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec on modern CPUs
    internal_s_buffer = (char *)malloc(len);
    if (!internal_s_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Fill buffer with non-zero bytes to simulate string data
    memset(internal_s_buffer, 'x', len - 1);
    // Place null terminator near the end to ensure loop runs long but terminates
    internal_s_buffer[len - 1] = '\0';

    s = internal_s_buffer;
    i = 0;
}