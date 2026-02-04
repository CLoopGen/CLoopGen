#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *key;
int keylen;
int s;
int e;

void init_vars() {
    keylen = 134217728; // 128 MB data size for ~0.01 sec runtime
    s = 0;
    key = (char*)malloc(keylen);
    if (!key) exit(1);

    // Fill with non-} characters up to near the end
    for (int i = s + 1; i < keylen - 1; i++) {
        key[i] = 'a';
    }
    // Place '}' near the end so loop breaks before exceeding bounds
    key[keylen - 1] = '}';
}