#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_s_buffer = NULL;

void init_vars() {
    size_t data_size = 64 << 20; // 64 MB for ~0.01 sec runtime on typical CPU
    internal_s_buffer = (char *)malloc(data_size);
    if (!internal_s_buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to simulate string data
    memset(internal_s_buffer, 'x', data_size - 1);
    internal_s_buffer[data_size - 1] = '\0'; // null-terminate to ensure loop stops

    s = internal_s_buffer;
    len = data_size;
    i = 0;
}