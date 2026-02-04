#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *ep;
char *cp;

static char *buffer;
static size_t buffer_size = 64 << 20; // 64 MB

void init_vars() {
    buffer = (char *)malloc(buffer_size);
    if (!buffer) {
        exit(1);
    }

    memset(buffer, 'A', buffer_size - 1);
    buffer[buffer_size - 1] = '\x00';

    cp = buffer;
    ep = buffer + buffer_size;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}