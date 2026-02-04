#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;
int e;

void init_vars() {
    keylen = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPU
    s = 0;
    e = 0;

    key = (char*)malloc(keylen);
    if (!key) exit(1);

    // Fill with non-terminating character
    for (int i = 0; i < keylen - 1; i++) {
        key[i] = 'a';
    }
    // Place '}' near the end to ensure loop runs long but terminates
    key[keylen - 1] = '}';
}