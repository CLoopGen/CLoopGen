#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;

void init_vars() {
    keylen = 67108864; // 64MB size for ~0.01 sec runtime on modern CPU
    key = (char *)malloc(keylen);
    if (!key) {
        exit(1);
    }
    for (int i = 0; i < keylen - 1; i++) {
        key[i] = 'A' + (i % 26);
    }
    key[keylen - 1] = '{'; // ensure break condition is met at last element
}