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
    len = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec on modern CPU
    buffer = (char *)malloc(len);
    if (!buffer) {
        exit(1);
    }
    memset(buffer, 'x', len - 1); // Fill with non-zero
    buffer[len - 1] = '\0';       // Null terminate at end
    s = buffer;                   // Point s to buffer
    i = 0;                        // Initialize loop index
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}