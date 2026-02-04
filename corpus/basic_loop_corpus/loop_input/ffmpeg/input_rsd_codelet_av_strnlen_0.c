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
    len = 100000000; // ~100MB to achieve ~0.01 sec runtime on modern CPU
    s = (char *)malloc(len);
    if (!s) {
        exit(1);
    }
    memset(s, 'x', len - 1); // Fill with non-zero
    s[len - 1] = '\0'; // Ensure loop terminates at the last character
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}