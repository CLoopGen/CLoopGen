#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *key;
int keylen;
int s;

void init_vars() {
    keylen = 67108864; // ~64MB to achieve around 0.01 sec on modern CPU
    key = (char *)malloc(keylen);
    if (!key) {
        keylen = 0;
        return;
    }
    memset(key, 'A', keylen);
    int target_pos = rand() % keylen;
    if (target_pos >= 0 && target_pos < keylen) {
        key[target_pos] = '{';
    }
    s = 0;
}