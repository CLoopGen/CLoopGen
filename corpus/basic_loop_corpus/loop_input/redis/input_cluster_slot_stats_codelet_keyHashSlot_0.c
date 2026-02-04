#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;

void init_vars() {
    keylen = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime
    key = (char*)malloc(keylen);
    if (!key) {
        keylen = 0;
        return;
    }
    // Fill with non-breaking characters except at the end
    for (int i = 0; i < keylen - 1; i++) {
        key[i] = 'A';
    }
    key[keylen - 1] = '{'; // Place '{' at last position to force full loop iteration
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}