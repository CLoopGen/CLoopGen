#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *key;
int keylen;
int s;
int e;

void init_vars() {
    keylen = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime on modern CPU
    s = 0;
    e = 0;

    key = (char*)malloc(keylen);
    if (!key) {
        keylen = 0;
        return;
    }

    memset(key, 'x', keylen - 1); // Fill with non-'}' characters
    key[keylen - 1] = '}'; // Place '}' at the end to ensure loop breaks eventually
}