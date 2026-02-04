#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 10000000; // ~10 million bytes to target ~0.01 sec runtime
    s = (char*)malloc(len);
    if (!s) {
        exit(1);
    }
    memset(s, 'x', len - 1); // fill with non-zero
    s[len - 1] = '\0'; // null terminate to trigger loop exit
}