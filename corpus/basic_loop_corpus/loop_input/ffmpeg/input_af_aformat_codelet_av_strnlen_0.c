#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 134217728; // 128 MB to target ~0.01 sec on modern CPU
    s = (char *)malloc(len);
    if (!s) exit(1);

    // Fill with non-null bytes, null-terminating near the end to ensure loop runs long but terminates
    memset(s, 'A', len - 1);
    s[len - 1] = '\0';
}