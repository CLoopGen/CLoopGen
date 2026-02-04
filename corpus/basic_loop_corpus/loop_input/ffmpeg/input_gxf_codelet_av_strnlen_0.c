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
    len = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPUs for simple loop
    internal_s_buffer = (char *)malloc(len);
    if (!internal_s_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Fill with non-zero bytes to ensure loop runs full length except last byte
    memset(internal_s_buffer, 'A', len - 1);
    internal_s_buffer[len - 1] = '\0'; // Null terminate at end so loop stops at boundary

    s = internal_s_buffer;
    i = 0;
}