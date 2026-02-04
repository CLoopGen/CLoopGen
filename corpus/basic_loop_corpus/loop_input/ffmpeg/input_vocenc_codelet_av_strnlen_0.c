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

void init_vars() {
    len = 128 * 1024 * 1024; // 128 MB
    buffer = (char *)malloc(len);
    if (!buffer) {
        exit(1);
    }
    memset(buffer, 'x', len - 1);
    buffer[len - 1] = '\0'; // ensure loop terminates at end
    s = buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}