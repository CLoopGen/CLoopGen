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
    keylen = 67108864; // ~64MB to target ~0.01 sec runtime on modern CPU
    key = (char *)malloc(keylen);
    if (!key) {
        keylen = 0;
        return;
    }

    memset(key, 'A', keylen);
    int break_position = keylen * 0.9; // Place '{' near end to ensure loop runs long enough
    key[break_position] = '{';
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}