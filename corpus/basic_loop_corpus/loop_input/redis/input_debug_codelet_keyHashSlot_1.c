#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;
int e;

void init_vars() {
    keylen = 64 * 1024 * 1024;
    s = 0;
    key = (char*)malloc(keylen);
    if (!key) {
        exit(1);
    }
    for (int i = 0; i < keylen - 1; i++) {
        key[i] = (i == s + 1 + 1000000) ? '}' : 'a';
    }
    key[keylen - 1] = '}';
}