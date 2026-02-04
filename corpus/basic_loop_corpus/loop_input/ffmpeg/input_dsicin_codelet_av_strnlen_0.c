#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_buffer;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB
    internal_buffer = (char *)malloc(data_size);
    if (!internal_buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to simulate string data
    memset(internal_buffer, 'x', data_size);

    // Place a null terminator near the end to trigger loop termination close to the end
    internal_buffer[data_size - 1] = '\0';

    s = internal_buffer;
    len = data_size;
    i = 0;
}