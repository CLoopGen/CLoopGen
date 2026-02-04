#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;

void init_vars() {
    keylen = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPU
    key = (char*)malloc(keylen);
    if (!key) {
        exit(1);
    }
    for (int i = 0; i < keylen - 1; i++) {
        key[i] = 'A'; // Fill with non-'{' characters
    }
    key[keylen - 1] = '{'; // Place '{' at the end to ensure loop runs through most of the array
}