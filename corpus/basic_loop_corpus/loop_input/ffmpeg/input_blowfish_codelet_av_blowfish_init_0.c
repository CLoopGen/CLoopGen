#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVBlowfish {
    uint32_t p[18];
    uint32_t s[4][256];
} AVBlowfish;

uint32_t orig_p[18];
AVBlowfish *ctx;
uint8_t *key;
int key_len;
uint32_t data;
int i;
int j;
int k;

void init_vars() {
    for (int idx = 0; idx < 18; ++idx) {
        orig_p[idx] = idx * 0x1234567U;
    }

    ctx = (AVBlowfish*)malloc(sizeof(AVBlowfish));
    if (!ctx) exit(1);

    key_len = 1024;
    key = (uint8_t*)malloc(key_len);
    if (!key) exit(1);
    for (int idx = 0; idx < key_len; ++idx) {
        key[idx] = idx & 0xFF;
    }

    data = 0;
    i = 0;
    j = 0;
    k = 0;
}