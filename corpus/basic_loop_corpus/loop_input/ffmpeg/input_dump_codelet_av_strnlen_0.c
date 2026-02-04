#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 134217728; // ~128MB to target ~0.01 sec runtime on modern CPU
    s = malloc(len);
    if (!s) {
        exit(1);
    }
    memset(s, 'x', len - 1); // fill with non-zero
    s[len - 1] = '\0'; // null terminate so loop stops at end
}

// Ensure symbols are defined for linkage with loop()