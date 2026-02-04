#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;
int e;

void init_vars() {
    keylen = 134217728; // 128MB data size for ~0.01 sec runtime
    s = 0;
    e = 0;

    key = (char*)malloc(keylen);
    if (!key) exit(1);

    for (int i = 0; i < keylen - 1; i++) {
        key[i] = (i == s + 1 + 1000000) ? '}' : 'a'; // place '}' at a predictable position after s+1
    }
    key[keylen - 1] = 'a'; // ensure last element is safe
}