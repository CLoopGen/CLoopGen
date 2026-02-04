#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    len = 16777216; // 16MB size for ~0.01 sec on modern CPU
    buffer = (char *)malloc(len);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Fill with non-zero bytes except at the end to trigger loop condition
    memset(buffer, 'A', len - 1);
    buffer[len - 1] = 0; // null terminator near the end

    s = buffer;
    i = 0;
}