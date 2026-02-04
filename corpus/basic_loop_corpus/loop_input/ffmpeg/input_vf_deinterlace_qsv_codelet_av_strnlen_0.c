#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 100000000; // ~100 million bytes to target ~0.01 sec runtime on modern CPU
    s = (char*)malloc(len);
    if (!s) exit(1);

    size_t fill_len = len - 1;
    memset(s, 'x', fill_len);
    s[fill_len] = '\0'; // Ensure loop stops at null terminator
}