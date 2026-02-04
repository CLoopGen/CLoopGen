#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void loop();

void init_vars() {
    len = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec runtime on modern CPU
    s = (char*)malloc(len);
    if (!s) {
        exit(1);
    }
    memset(s, 'x', len - 1); // Fill with non-zero
    s[len - 1] = '\0'; // Ensure loop stops at the end
}

static int initialized = 0;

__attribute__((constructor))
void ensure_init() {
    if (!initialized) {
        init_vars();
        initialized = 1;
    }
}