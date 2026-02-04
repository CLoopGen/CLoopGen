#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
char *peek;

static char *buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    buffer = (char *)malloc(data_size);
    if (!buffer) {
        exit(1);
    }

    // Fill with spaces and tabs, then terminate with a non-whitespace character
    memset(buffer, ' ', data_size - 1);
    for (size_t i = 1; i < data_size - 1; i += 2) {
        buffer[i] = '\t';
    }
    buffer[data_size - 1] = 'x'; // Ensures loop stops before out-of-bounds

    s = buffer;
    peek = s;
}