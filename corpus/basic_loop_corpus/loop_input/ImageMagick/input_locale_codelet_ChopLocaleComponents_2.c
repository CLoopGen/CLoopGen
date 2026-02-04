#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *path;
size_t components;
char *p;
ssize_t count;

static char *buffer;
static size_t buffer_size;

void init_vars() {
    buffer_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime
    buffer = (char *)malloc(buffer_size);
    if (!buffer) exit(1);

    // Fill buffer with path-like data: multiple components separated by '/'
    size_t pos = 0;
    components = 0;
    while (pos < buffer_size - 100) {
        size_t len = rand() % 50 + 5; // Random component length
        memset(buffer + pos, 'a', len);
        pos += len;
        if (pos < buffer_size - 1) {
            buffer[pos++] = '/';
            components++;
        }
    }
    buffer[buffer_size - 1] = '\0';
    if (components > 0) {
        components--; // Adjust so loop terminates correctly
    }

    path = buffer;
    p = buffer + buffer_size - 1; // Start from near end
    count = 0;
}