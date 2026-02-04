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
static size_t buffer_size;

void init_vars() {
    buffer_size = 128 * 1024 * 1024; // 128 MB
    internal_buffer = (char *)calloc(buffer_size, sizeof(char));
    if (!internal_buffer) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < buffer_size - 1; idx++) {
        internal_buffer[idx] = 'x';
    }
    internal_buffer[buffer_size - 1] = '\0';

    s = internal_buffer;
    len = buffer_size;
    i = 0;
}