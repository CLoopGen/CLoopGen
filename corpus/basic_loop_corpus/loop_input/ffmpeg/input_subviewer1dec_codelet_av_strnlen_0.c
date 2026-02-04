#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 16777216; // 16MB to target ~0.01 sec runtime on modern CPU
    s = (char*)malloc(len);
    if (!s) {
        exit(1);
    }
    for (size_t idx = 0; idx < len - 1; idx++) {
        s[idx] = 'x'; // non-zero to keep loop condition active
    }
    s[len - 1] = '\0'; // null terminator to break loop at last element
}