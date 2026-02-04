#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;
int e;

void init_vars() {
    keylen = 1 << 20; // ~1MB of data
    s = 0;
    e = 0;

    key = (char *)malloc(keylen);
    if (!key) {
        exit(1);
    }

    // Fill with 'a' except place a '}' at the end to ensure loop breaks
    for (int i = 0; i < keylen - 1; i++) {
        key[i] = 'a';
    }
    key[keylen - 1] = '}';
}