#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;
int e;

void init_vars() {
    keylen = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    s = 0;
    e = 0;

    key = (char*)malloc(keylen);
    if (!key) {
        exit(1);
    }

    // Fill with 'a' except place a '}' near the end to ensure break happens within bounds
    for (int i = 0; i < keylen - 1; i++) {
        key[i] = 'a';
    }
    key[keylen - 1] = '}';
}