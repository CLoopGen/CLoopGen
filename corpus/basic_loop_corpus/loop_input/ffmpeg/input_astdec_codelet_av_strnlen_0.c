#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime on modern CPU
    s = (char *)malloc(len);
    if (!s) {
        exit(1);
    }
    // Fill with non-zero bytes to prevent premature termination
    for (size_t j = 0; j < len - 1; j++) {
        s[j] = 'x';
    }
    // Null terminate at the end to ensure loop terminates within bounds
    s[len - 1] = '\0';
}