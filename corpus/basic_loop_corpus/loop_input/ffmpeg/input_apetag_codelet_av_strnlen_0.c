#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *internal_buffer;

void init_vars() {
    len = 128 << 20; // 128 MB
    internal_buffer = (char *)malloc(len);
    if (!internal_buffer) {
        exit(1);
    }
    memset(internal_buffer, 'x', len - 1);
    internal_buffer[len - 1] = '\0';
    s = internal_buffer;
}