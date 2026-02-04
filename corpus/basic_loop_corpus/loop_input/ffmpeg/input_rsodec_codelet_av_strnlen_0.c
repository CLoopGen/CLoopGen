#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_buffer = NULL;

void init_vars() {
    if (internal_buffer != NULL) {
        free(internal_buffer);
    }

    len = 134217728; // 128 MB to target ~0.01 sec on modern CPUs
    internal_buffer = (char *)malloc(len);
    if (!internal_buffer) {
        len = 0;
        s = NULL;
        return;
    }

    memset(internal_buffer, 'x', len - 1);
    internal_buffer[len - 1] = '\0';

    s = internal_buffer;
    i = 0;
}