#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void loop(void);

void init_vars() {
    len = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec on modern CPUs
    s = malloc(len);
    if (!s) {
        exit(1);
    }
    // Fill with non-zero bytes, but ensure a zero near the end to satisfy s[i] condition
    memset(s, 1, len - 1);
    s[len - 1] = 0; // Null terminate at the last byte
}