#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *key;
int i;
int j;
uint8_t y;
uint8_t *state;
int keylen;

void init_vars() {
    keylen = 32;
    key = malloc(keylen);
    state = malloc(256 * sizeof(uint8_t));

    if (!key || !state) {
        exit(EXIT_FAILURE);
    }

    for (int idx = 0; idx < keylen; ++idx) {
        key[idx] = (uint8_t)(idx + 1);
    }

    for (int idx = 0; idx < 256; ++idx) {
        state[idx] = (uint8_t)idx;
    }

    i = 0;
    j = 0;
    y = 0;
}