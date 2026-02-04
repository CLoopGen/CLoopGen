#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *internal_s_buffer;

void init_vars() {
    len = 100 * 1024 * 1024; // ~100 million iterations for ~0.01 sec on modern CPU
    internal_s_buffer = malloc(len);
    if (!internal_s_buffer) {
        exit(1);
    }
    memset(internal_s_buffer, 'x', len - 1); // Fill with non-zero
    internal_s_buffer[len - 1] = '\0'; // Null terminate at end to trigger loop exit
    s = internal_s_buffer;
    i = 0;
}