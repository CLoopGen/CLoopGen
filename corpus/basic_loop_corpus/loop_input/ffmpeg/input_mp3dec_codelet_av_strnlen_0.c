#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    len = 100 * 1024 * 1024; // 100 MB to ensure ~0.01 sec runtime on modern CPUs
    buffer = (char *)malloc(len);
    if (!buffer) {
        exit(1);
    }
    memset(buffer, 'x', len - 1); // Fill with non-zero
    buffer[len - 1] = '\0'; // Null terminate at end to trigger loop exit
    s = buffer;
    i = 0;
}