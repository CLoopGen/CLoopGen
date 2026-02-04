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
    key = (char *)malloc(keylen);
    if (!key) {
        exit(1);
    }
    // Fill with non-terminating character initially
    for (int i = 0; i < keylen; i++) {
        key[i] = 'a';
    }
    // Place '}' near the end to ensure loop runs long enough
    key[s + 1 + keylen - 1000] = '}';
}

void loop(); // forward declaration

// Ensure linkage and correctness when called from outside
__attribute__((constructor))
static void constructor() {
    init_vars();
}