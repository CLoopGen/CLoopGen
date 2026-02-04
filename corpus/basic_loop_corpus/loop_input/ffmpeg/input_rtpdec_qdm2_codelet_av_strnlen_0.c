#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 10000000; // ~10 million bytes to target ~0.01 sec runtime
    s = (char*)malloc(len);
    if (!s) exit(1);

    // Fill with non-zero except near the end to ensure loop runs long but terminates
    for (size_t j = 0; j < len - 1; j++) {
        s[j] = 'x';
    }
    s[len - 1] = '\0'; // null terminator to break loop at final index
}