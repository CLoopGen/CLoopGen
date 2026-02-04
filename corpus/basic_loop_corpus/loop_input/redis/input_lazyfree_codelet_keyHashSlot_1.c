#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *key;
int keylen;
int s;
int e;

void init_vars() {
    keylen = 134217728; // ~128MB to target ~0.01 sec on modern CPU
    key = (char*)malloc(keylen);
    if (!key) {
        exit(1);
    }

    // Fill with random data, but ensure a '}' exists beyond s
    s = 1000000; // Start searching from 1M
    for (int i = 0; i < keylen; ++i) {
        key[i] = 'a' + (rand() % 26);
    }
    // Place '}' at a position after s to trigger break within loop bounds
    key[s + 500000] = '}';
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}