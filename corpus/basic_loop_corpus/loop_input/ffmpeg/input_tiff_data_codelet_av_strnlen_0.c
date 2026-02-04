#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 1 << 20; // Approximately 1MB of data
    s = (char *)malloc(len);
    if (!s) {
        exit(1);
    }
    memset(s, 'x', len - 1); // Fill with non-zero bytes
    s[len - 1] = '\0'; // Null terminate at the end to trigger loop exit
}