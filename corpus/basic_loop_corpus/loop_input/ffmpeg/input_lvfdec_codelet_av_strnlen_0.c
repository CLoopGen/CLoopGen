#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPU
    s = (char*)malloc(len);
    if (!s) exit(1);

    // Fill with non-zero except at the end to trigger loop termination
    for (size_t idx = 0; idx < len - 1; ++idx) {
        s[idx] = 'x';
    }
    s[len - 1] = '\0'; // null terminator to break loop
}