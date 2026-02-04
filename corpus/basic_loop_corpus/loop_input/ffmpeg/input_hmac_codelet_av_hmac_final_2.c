#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef void (*hmac_final)(void *, uint8_t *);

typedef void (*hmac_update)(void *, const uint8_t *, int);

typedef void (*hmac_init)(void *);

struct AVHMAC {
    void *hash;
    int blocklen;
    int hashlen;
    hmac_final final;
    hmac_update update;
    hmac_init init;
    uint8_t key[128];
    int keylen;
};

typedef struct AVHMAC AVHMAC;

AVHMAC *c;
uint8_t block[128];
int i;

void init_vars() {
    c = malloc(sizeof(AVHMAC));
    if (!c) exit(1);

    c->hash = NULL;
    c->blocklen = 64;
    c->hashlen = 32;
    c->final = NULL;
    c->update = NULL;
    c->init = NULL;
    c->keylen = 64;

    for (int j = 0; j < c->keylen; j++) {
        c->key[j] = (uint8_t)(j & 0xFF);
    }

    for (int j = 0; j < 128; j++) {
        block[j] = 0;
    }

    i = 0;
}