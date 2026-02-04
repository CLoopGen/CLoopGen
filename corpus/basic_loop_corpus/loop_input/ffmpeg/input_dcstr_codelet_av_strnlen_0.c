#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 100 * 1024 * 1024; // ~100 million bytes to target ~0.01 sec runtime
    s = (char*)malloc(len);
    if (!s) exit(1);

    // Fill with non-zero except at the end to trigger loop condition s[i] == 0
    memset(s, 1, len - 1);
    s[len - 1] = 0; // ensure loop stops at last byte
}