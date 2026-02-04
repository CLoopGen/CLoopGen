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
    len = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec runtime on modern CPUs
    internal_s_buffer = (char *)malloc(len);
    if (!internal_s_buffer) {
        exit(1);
    }
    // Fill with non-zero bytes to ensure loop condition 's[i]' breaks on null
    memset(internal_s_buffer, 'x', len - 1);
    internal_s_buffer[len - 1] = '\0'; // Ensure loop terminates at or before boundary
    s = internal_s_buffer;
    i = 0;
}