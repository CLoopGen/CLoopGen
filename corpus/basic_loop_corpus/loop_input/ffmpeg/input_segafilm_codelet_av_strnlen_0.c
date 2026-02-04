#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec on modern CPUs
    s = (char *)malloc(len);
    if (!s) exit(1);

    // Fill with non-zero bytes to ensure loop runs full length
    memset(s, 'A', len - 1);
    s[len - 1] = '\0'; // Null terminate so condition `s[i]` triggers exit at last byte
}