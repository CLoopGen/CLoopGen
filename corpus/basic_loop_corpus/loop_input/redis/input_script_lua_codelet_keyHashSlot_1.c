#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;
int e;

void init_vars() {
    keylen = 67108864; // ~64MB to target ~0.01 sec runtime on modern CPU
    s = 0;
    e = 0;
    key = (char*)malloc(keylen);
    if (!key) exit(1);

    for (int i = 0; i < keylen - 1; i++) {
        key[i] = (i == s + 1 + 1000000) ? '}' : 'a'; // place '}' at position s+1+1e6 to ensure loop runs sufficiently
    }
    key[keylen - 1] = '}';
}