#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 10000000; // ~10 million characters to target ~0.01 sec runtime
    s = (char *)malloc(len);
    if (!s) exit(1);

    size_t fill_len = len - 1;
    memset(s, 'x', fill_len);
    s[fill_len] = '\0'; // null-terminate so loop stops at end
}