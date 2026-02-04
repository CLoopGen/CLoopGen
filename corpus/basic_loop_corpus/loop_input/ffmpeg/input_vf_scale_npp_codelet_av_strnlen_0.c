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
    const size_t target_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on modern CPU
    internal_s_buffer = (char *)malloc(target_size);
    if (!internal_s_buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to simulate string data
    memset(internal_s_buffer, 'A', target_size - 1);
    // Place null terminator near the end to trigger loop termination by s[i] condition
    internal_s_buffer[target_size - 1] = '\0';

    s = internal_s_buffer;
    len = target_size;
    i = 0;
}