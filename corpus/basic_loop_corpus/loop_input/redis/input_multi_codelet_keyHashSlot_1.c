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
    if (!key) exit(1);

    for (int i = 0; i < keylen - 1; i++) {
        key[i] = (i == keylen / 2) ? '}' : 'a';
    }
    key[keylen - 1] = '}'; // Ensure there's a closing brace at the end
}