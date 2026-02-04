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
    if (!s) {
        exit(1);
    }
    // Fill with non-zero except near the end to ensure loop runs most of the way
    for (size_t j = 0; j < len - 1; j++) {
        s[j] = 'a';
    }
    s[len - 1] = '\0'; // null terminator to break loop at final element
}