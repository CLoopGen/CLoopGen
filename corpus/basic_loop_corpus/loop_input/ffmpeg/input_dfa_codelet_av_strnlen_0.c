#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 64 * 1024 * 1024; // 64 MB to ensure ~0.01 sec runtime on modern CPU
    s = (char *)malloc(len);
    if (!s) exit(1);

    // Fill with non-zero bytes to simulate string data
    memset(s, 'x', len - 1);
    s[len - 1] = '\0'; // null-terminate so loop condition s[i] fails at end
}