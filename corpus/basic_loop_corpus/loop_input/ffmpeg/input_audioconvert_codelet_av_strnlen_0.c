#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 100000000; // ~100 million elements for ~0.01 sec runtime on modern CPU
    s = malloc(len);
    if (!s) {
        exit(1);
    }
    // Fill with non-zero bytes except at the end to ensure loop runs through most of the array
    for (size_t j = 0; j < len - 1; j++) {
        s[j] = 'x';
    }
    s[len - 1] = '\0'; // null terminator to break the loop
}