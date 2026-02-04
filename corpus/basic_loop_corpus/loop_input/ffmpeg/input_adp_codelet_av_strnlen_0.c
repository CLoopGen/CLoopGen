#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *buffer;
static size_t buffer_size;

void init_vars() {
    buffer_size = 128 << 20; // 128 MB
    buffer = (char*)malloc(buffer_size);
    if (!buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to simulate string data
    memset(buffer, 'A', buffer_size - 1);
    buffer[buffer_size - 1] = '\0'; // null-terminate at the end

    s = buffer;
    len = buffer_size;
    i = 0;
}