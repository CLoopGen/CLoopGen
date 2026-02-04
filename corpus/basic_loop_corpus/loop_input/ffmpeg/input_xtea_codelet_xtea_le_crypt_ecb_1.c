#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVXTEA {
    uint32_t key[16];
} AVXTEA;

AVXTEA *ctx;
uint32_t v0;
uint32_t v1;
int i;
uint32_t delta;
uint32_t sum;

void init_vars() {
    ctx = (AVXTEA*)malloc(sizeof(AVXTEA));
    if (!ctx) {
        exit(1);
    }
    for (int j = 0; j < 16; j++) {
        ctx->key[j] = 0xdeadbeef ^ (j * 0x9e3779b9);
    }
    v0 = 0x12345678;
    v1 = 0xabcdef01;
    delta = 0x9e3779b9;
    sum = 0xc0defeed;
}
