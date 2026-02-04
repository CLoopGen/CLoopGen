#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    len = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec on modern CPUs
    buffer = (char *)malloc(len);
    if (!buffer) {
        exit(1);
    }
    for (size_t idx = 0; idx < len - 1; ++idx) {
        buffer[idx] = 'x'; // Non-zero to keep loop condition active
    }
    buffer[len - 1] = '\0'; // Null terminator to break loop
    s = buffer;
    i = 0;
}