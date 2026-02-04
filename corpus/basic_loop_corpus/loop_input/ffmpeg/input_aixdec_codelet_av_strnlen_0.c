#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

static char *internal_s;
static size_t internal_len;

void init_vars() {
    internal_len = 134217728; // 128 MB to target ~0.01 sec on modern CPU
    internal_s = (char *)malloc(internal_len);
    if (!internal_s) {
        exit(1);
    }

    // Fill with non-zero bytes to ensure loop runs full length
    memset(internal_s, 'x', internal_len - 1);
    internal_s[internal_len - 1] = '\0'; // null-terminate to satisfy s[i] condition

    // Initialize external symbols
    s = internal_s;
    len = internal_len;
    i = 0;
}