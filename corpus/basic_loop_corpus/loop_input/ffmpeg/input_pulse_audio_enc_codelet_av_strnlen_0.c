#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 134217728; // 128 MB to target ~0.01 sec on modern CPUs
    s = (char *)malloc(len);
    if (!s) exit(1);

    // Fill with non-zero bytes to ensure loop runs full length
    memset(s, 'x', len - 1);
    // Null terminate at the end to satisfy s[i] condition
    s[len - 1] = '\0';
}