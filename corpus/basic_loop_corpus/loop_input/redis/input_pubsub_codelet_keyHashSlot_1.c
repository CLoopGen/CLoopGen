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
    e = 0;

    key = (char*)malloc(keylen);
    if (!key) exit(1);

    // Fill with non-terminating character up to a point near the end
    for (int i = 0; i < keylen - 1; i++) {
        key[i] = 'a';
    }
    // Place '}' at the last position so loop runs through most of the array before breaking
    key[keylen - 1] = '}';
}