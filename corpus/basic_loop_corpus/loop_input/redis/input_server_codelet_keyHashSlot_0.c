#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;

void init_vars() {
    keylen = 16777216; // ~16MB data size for ~0.01 sec runtime
    key = (char *)malloc(keylen);
    if (!key) {
        exit(1);
    }
    for (int i = 0; i < keylen - 1; i++) {
        key[i] = 'A' + (i % 26);
    }
    key[keylen - 1] = '{'; // Ensure '{' is found at the last position to prevent out-of-bounds and trigger break
}