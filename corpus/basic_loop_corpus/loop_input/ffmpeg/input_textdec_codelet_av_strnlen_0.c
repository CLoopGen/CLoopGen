#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 100000000; // ~100MB to target ~0.01 sec on modern CPU
    s = (char*)malloc(len);
    if (!s) exit(1);

    // Fill with non-zero bytes to ensure loop runs full length
    for (size_t j = 0; j < len - 1; j++) {
        s[j] = 'x';
    }
    s[len - 1] = '\0'; // Ensure loop stops at last element
}

__attribute__((constructor))
static void ctor() {
    init_vars();
}