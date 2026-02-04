#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;
int e;

void init_vars() {
    keylen = 134217728; // ~128MB to achieve ~0.01s runtime on modern CPU
    s = 0;
    e = 0;

    key = (char*)malloc(keylen);
    if (!key) {
        exit(1);
    }

    for (int i = 0; i < keylen - 1; i++) {
        key[i] = 'a'; // Fill with non-terminating character
    }
    key[keylen - 1] = '}'; // Place '}' at the end to ensure loop breaks eventually
}