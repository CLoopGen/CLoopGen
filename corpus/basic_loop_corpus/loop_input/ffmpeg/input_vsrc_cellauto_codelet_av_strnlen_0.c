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
    len = 100 * 1024 * 1024; // 100 MB to target ~0.01 sec on modern CPUs
    buffer = (char *)malloc(len);
    if (!buffer) {
        exit(1);
    }

    // Fill with non-zero bytes to ensure loop runs through most of the data
    memset(buffer, 'x', len - 1);
    // Null terminate at the end to ensure s[i] eventually becomes false
    buffer[len - 1] = '\0';

    s = buffer;
    i = 0;
}