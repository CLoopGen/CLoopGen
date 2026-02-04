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
    if (!s) exit(1);

    size_t fill_len = len - 1;
    for (size_t idx = 0; idx < fill_len; ++idx) {
        s[idx] = 'x';
    }
    s[fill_len] = '\0'; // Ensure null-termination so loop stops at null
}

__attribute__((constructor))
static void ctor() {
    init_vars();
}