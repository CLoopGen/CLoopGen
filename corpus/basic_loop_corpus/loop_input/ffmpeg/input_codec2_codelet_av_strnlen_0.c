#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 10000000; // ~10 million bytes to target ~0.01 sec runtime
    s = malloc(len);
    if (!s) {
        exit(1);
    }
    for (size_t j = 0; j < len - 1; j++) {
        s[j] = 'x'; // non-zero to keep loop condition active
    }
    s[len - 1] = '\0'; // null terminator to break loop
}