#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 128 * 1024 * 1024; // 128 MB
    s = (char *)malloc(len);
    if (!s) {
        exit(1);
    }
    // Fill with non-zero bytes except for a null terminator at the end
    for (size_t j = 0; j < len - 1; j++) {
        s[j] = 'a';
    }
    s[len - 1] = '\0'; // Ensure loop stops at the last byte
}