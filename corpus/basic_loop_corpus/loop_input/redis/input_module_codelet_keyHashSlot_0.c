#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;

void init_vars() {
    keylen = 1 << 20; // 1MB of data
    key = (char *)malloc(keylen);
    if (!key) {
        exit(1);
    }
    for (int i = 0; i < keylen - 1; i++) {
        key[i] = 'A'; // Fill with non-'{' characters
    }
    key[keylen - 1] = '{'; // Place '{' at the end to ensure loop breaks on last iteration
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}