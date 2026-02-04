#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *key;
int keylen;
int s;

void init_vars() {
    keylen = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime
    key = (char *)malloc(keylen);
    if (!key) {
        exit(1);
    }
    memset(key, 'A', keylen);
    key[keylen - 1] = '{'; // Ensure '{' is found at the end to prevent OOB
}

__attribute__((destructor))
void cleanup() {
    free(key);
}