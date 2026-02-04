#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *key;
int keylen;
int s;

void init_vars() {
    keylen = 67108864; // ~64MB to target ~0.01 sec runtime on modern CPU
    key = (char*)malloc(keylen);
    if (!key) {
        exit(1);
    }
    memset(key, 'A', keylen - 1); // Fill with non-'{' chars
    key[keylen - 1] = '{'; // Place '{' at end to ensure loop runs through most of array
}

__attribute__((constructor))
static void ctor() {
    init_vars();
}