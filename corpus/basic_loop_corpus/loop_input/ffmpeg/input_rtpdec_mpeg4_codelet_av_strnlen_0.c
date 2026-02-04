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
    size_t data_size = 128 * 1024 * 1024; // 128 MB for ~0.01 sec runtime on modern CPU
    internal_buffer = (char*)malloc(data_size);
    if (!internal_buffer) {
        exit(1);
    }

    // Fill with non-null bytes except a null terminator at the end
    memset(internal_buffer, 'A', data_size - 1);
    internal_buffer[data_size - 1] = '\0';

    s = internal_buffer;
    len = data_size;
    i = 0;
}