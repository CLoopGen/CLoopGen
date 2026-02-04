#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

static char *buffer;

void init_vars() {
    len = 1 << 20; // 1MB of data for ~0.01 sec runtime on modern CPU
    buffer = (char*)malloc(len);
    if (!buffer) {
        exit(1);
    }
    for (size_t idx = 0; idx < len - 1; idx++) {
        buffer[idx] = 'x'; // non-zero to keep loop condition active
    }
    buffer[len - 1] = '\0'; // null terminator to break the loop
    s = buffer;
    i = 0;
}

void loop(); // Forward declaration to avoid implicit declaration error

// Ensure proper linkage when calling loop from other files