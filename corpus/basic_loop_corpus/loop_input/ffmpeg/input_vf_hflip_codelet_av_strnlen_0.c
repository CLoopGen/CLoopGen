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
    size_t data_size = 64 * 1024 * 1024;
    internal_s_buffer = (char *)malloc(data_size);
    if (!internal_s_buffer) {
        exit(1);
    }
    memset(internal_s_buffer, 'x', data_size - 1);
    internal_s_buffer[data_size - 1] = '\0';

    s = internal_s_buffer;
    len = data_size;
    i = 0;
}