#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    len = 10000000; // 10 million characters to target ~0.01 sec runtime
    buffer = (char*)malloc(len);
    if (!buffer) {
        exit(1);
    }
    memset(buffer, 'x', len - 1);
    buffer[len - 1] = '\0'; // Ensure loop terminates at the last character
    s = buffer;
    i = 0;
}