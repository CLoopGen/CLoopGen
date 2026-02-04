#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *internal_buffer;

void init_vars() {
    len = 64 * 1024 * 1024; // 64 MB to ensure ~0.01 sec runtime on modern CPUs
    internal_buffer = (char *)malloc(len);
    if (!internal_buffer) {
        exit(1);
    }
    memset(internal_buffer, 'x', len - 1);
    internal_buffer[len - 1] = '\0'; // Ensure loop terminates at end
    s = internal_buffer;
    i = 0;
}