#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPUs
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        exit(1);
    }
    for (size_t j = 0; j < data_size - 1; j++) {
        buffer[j] = 'x'; // non-zero to keep loop condition active
    }
    buffer[data_size - 1] = '\0'; // null terminator to break loop

    s = buffer;
    len = data_size;
    i = 0;
}