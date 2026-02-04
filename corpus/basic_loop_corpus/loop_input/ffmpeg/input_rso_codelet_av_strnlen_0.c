#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 134217728; // 128 MB to target ~0.01 sec on modern CPU
    s = (char*)malloc(len);
    if (!s) {
        exit(1);
    }
    // Fill with non-zero bytes to delay termination condition
    memset(s, 'A', len - 1);
    // Null terminate near the end to ensure loop runs long but terminates safely
    s[len - 1] = '\0';
}

__attribute__((constructor))
static void constructor_call() {
    init_vars();
}