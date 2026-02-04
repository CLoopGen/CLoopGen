#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 134217728; // 128 MB to target ~0.01 sec runtime on modern CPU
    s = (char*)malloc(len);
    if (!s) exit(1);

    size_t fill_len = len - 1;
    for (size_t j = 0; j < fill_len; j++) {
        s[j] = 'x'; 
    }
    s[fill_len] = '\0'; // null terminator to break loop
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}