#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;

void init_vars() {
    keylen = 67108864; // ~64MB to target ~0.01 sec runtime on modern CPU
    key = (char*)malloc(keylen);
    if (!key) exit(1);

    for (int i = 0; i < keylen - 1; i++) {
        key[i] = 'A' + (i % 26);
    }
    key[keylen - 1] = '{'; // Place '{' at the end to ensure loop runs through most of the array
}