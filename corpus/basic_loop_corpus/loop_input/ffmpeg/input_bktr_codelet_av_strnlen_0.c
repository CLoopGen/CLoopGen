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
    len = 134217728; // 128 MB to target ~0.01 sec on modern CPU
    s = (char *)malloc(len);
    if (!s) {
        exit(EXIT_FAILURE);
    }
    memset(s, 'x', len - 1); // Fill with non-zero
    s[len - 1] = '\0'; // Ensure loop terminates at last element
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}