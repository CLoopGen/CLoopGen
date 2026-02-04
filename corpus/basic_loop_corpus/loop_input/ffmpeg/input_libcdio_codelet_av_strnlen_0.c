#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 134217728; // 128 MB to target ~0.01 sec runtime on modern CPU
    s = (char*)malloc(len);
    if (!s) exit(1);

    // Fill with non-zero bytes to ensure loop runs through most of the buffer
    for (size_t j = 0; j < len - 1; j++) {
        s[j] = 'x';
    }
    s[len - 1] = '\0'; // Null terminator to break the loop at the last byte
}