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
    len = 134217728; // 128 MB to target ~0.01 sec on modern CPU
    buffer = (char *)malloc(len);
    if (!buffer) {
        exit(1);
    }
    // Fill with non-zero except at the end to ensure loop runs nearly full length
    memset(buffer, 'x', len - 1);
    buffer[len - 1] = '\0'; // null terminator near end to trigger exit condition
    s = buffer;
    i = 0;
}