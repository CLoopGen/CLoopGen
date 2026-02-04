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
    len = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec runtime on modern CPU
    buffer = (char *)malloc(len);
    if (!buffer) {
        exit(1);
    }
    s = buffer;
    // Fill with non-zero except last byte to force loop to iterate nearly full length
    memset(buffer, 'x', len - 1);
    buffer[len - 1] = '\0';
}

__attribute__((constructor))
static void ctor() {
    init_vars();
}