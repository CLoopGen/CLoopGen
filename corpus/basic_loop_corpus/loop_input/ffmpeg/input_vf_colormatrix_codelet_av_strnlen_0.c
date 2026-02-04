#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 1 << 20; // Approximately 1MB of data
    s = malloc(len);
    if (!s) {
        exit(1);
    }
    memset(s, 'x', len - 1);
    s[len - 1] = '\0'; // Ensure loop terminates at the last character
}

void loop(); // Forward declaration to avoid implicit declaration error