#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;
int e;

void init_vars() {
    keylen = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime on modern CPU
    s = 0;
    e = s + 1;

    key = (char*)malloc(keylen);
    if (!key) exit(1);

    // Fill with non-matching data
    for (int i = 0; i < keylen - 1; i++) {
        key[i] = 'a' + (i % 25);
    }
    // Place '}' near the end to ensure loop runs most of the way
    key[keylen - 1] = '}';
}