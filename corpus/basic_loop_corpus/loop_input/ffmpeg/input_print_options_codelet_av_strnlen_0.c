#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    len = 100 * 1024 * 1024; // 100 MB to target ~0.01 sec on modern CPU
    buffer = (char *)malloc(len);
    if (!buffer) {
        exit(1);
    }
    memset(buffer, 'x', len - 1); // Fill with non-zero
    buffer[len - 1] = '\0';       // Null terminate at end
    s = buffer;                   // Assign to external pointer
    i = 0;
}