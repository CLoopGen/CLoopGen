#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 100000000; // ~100 million bytes to target ~0.01 sec runtime on modern CPU
    s = malloc(len);
    if (!s) {
        exit(1);
    }
    size_t init_len = len - 1;
    if (init_len > 0) {
        memset(s, 1, init_len);
        s[init_len] = 0;
    } else {
        s[0] = 0;
    }
}