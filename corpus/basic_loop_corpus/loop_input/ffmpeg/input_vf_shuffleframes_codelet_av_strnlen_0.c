#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *internal_s_buffer;

void init_vars() {
    len = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPUs
    internal_s_buffer = (char *)malloc(len);
    if (!internal_s_buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to ensure loop runs full length
    memset(internal_s_buffer, 'x', len - 1);
    internal_s_buffer[len - 1] = '\0'; // Ensure loop stops at end

    s = internal_s_buffer;
    i = 0;
}