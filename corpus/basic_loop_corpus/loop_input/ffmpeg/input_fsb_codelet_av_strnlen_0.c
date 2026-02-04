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
    for (size_t idx = 0; idx < len - 1; idx++) {
        s[idx] = 'x';
    }
    s[len - 1] = '\0'; // Ensure null terminator at the end to satisfy s[i] condition
}