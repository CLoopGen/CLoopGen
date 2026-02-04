#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 100000000; // ~100 million elements for ~0.01 sec runtime on modern CPU
    s = (char*)malloc(len);
    if (!s) {
        exit(1);
    }
    // Fill with non-zero except near the end to ensure loop terminates within bounds
    memset(s, 'x', len - 1);
    s[len - 1] = '\0'; // null-terminator to trigger loop exit condition
}