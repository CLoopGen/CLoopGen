#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 128 << 20; // 128 MB
    s = (char *)malloc(len);
    if (!s) {
        exit(1);
    }
    for (size_t j = 0; j < len - 1; j++) {
        s[j] = 'x';
    }
    s[len - 1] = '\0'; // Ensure null-termination to satisfy s[i] condition
}