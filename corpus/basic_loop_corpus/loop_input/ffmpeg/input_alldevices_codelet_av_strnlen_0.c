#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 100000000; // ~100 million elements for ~0.01 sec runtime on modern CPU
    s = (char*)malloc(len);
    if (!s) {
        exit(1);
    }
    memset(s, 1, len - 1); // Fill with non-zero bytes
    s[len - 1] = 0; // Null terminator at the end to satisfy `s[i]` condition
}