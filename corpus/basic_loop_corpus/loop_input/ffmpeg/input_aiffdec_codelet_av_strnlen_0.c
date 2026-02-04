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
    size_t target_size = 128 * 1024 * 1024; // 128 MB
    internal_buffer = (char *)malloc(target_size);
    if (!internal_buffer) {
        exit(1);
    }

    // Fill most of the buffer with non-zero bytes
    memset(internal_buffer, 'A', target_size - 1);
    // Place a null terminator near the end to ensure loop terminates within bounds
    internal_buffer[target_size - 1] = '\0';

    s = internal_buffer;
    len = target_size;
    i = 0;
}