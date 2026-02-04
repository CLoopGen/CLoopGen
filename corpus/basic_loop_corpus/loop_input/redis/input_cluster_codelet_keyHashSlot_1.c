#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;
int e;

void init_vars() {
    keylen = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime on modern CPU
    s = 0;
    e = s + 1;

    key = (char*)malloc(keylen);
    if (!key) exit(1);

    // Fill with non-terminating character initially
    for (int i = 0; i < keylen; i++) {
        key[i] = 'a';
    }

    // Place '}' at a valid position beyond s+1 to trigger break in loop
    // Ensure e will stop before exceeding keylen
    key[keylen - 1] = '}';
}