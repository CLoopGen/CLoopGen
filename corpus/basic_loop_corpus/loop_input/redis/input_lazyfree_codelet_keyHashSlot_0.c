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
        keylen = 0;
        return;
    }
    for (int i = 0; i < keylen - 1; i++) {
        key[i] = 'A' + (i % 26);
    }
    key[keylen - 1] = '{'; // Ensure loop breaks at last element
}