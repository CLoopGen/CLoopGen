#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 10000000; // Approximately 10 million bytes to target ~0.01 sec runtime
    s = malloc(len);
    if (!s) {
        exit(1);
    }
    memset(s, 'x', len - 1); // Fill with non-zero
    s[len - 1] = '\0'; // Null terminate so loop stops at end
}