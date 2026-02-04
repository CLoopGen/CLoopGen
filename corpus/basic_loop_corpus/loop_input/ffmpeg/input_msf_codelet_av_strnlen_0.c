#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *internal_buffer;

void init_vars() {
    len = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPUs
    internal_buffer = (char *)malloc(len);
    if (!internal_buffer) {
        exit(1);
    }
    memset(internal_buffer, 'x', len - 1); // Fill with non-zero
    internal_buffer[len - 1] = '\0';       // Null terminate at end

    s = internal_buffer;
    i = 0;
}