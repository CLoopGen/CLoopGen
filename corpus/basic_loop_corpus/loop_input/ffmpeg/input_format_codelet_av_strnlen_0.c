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
    len = 128 * 1024 * 1024; // 128 MB of data
    s = (char *)malloc(len);
    if (!s) {
        exit(1);
    }
    memset(s, 'x', len - 1); // Fill with non-zero
    s[len - 1] = '\0'; // Null terminator at the end to ensure loop stops here
}