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
int i;
uint8_t block[128];

void init_vars() {
    c = (AVHMAC*)malloc(sizeof(AVHMAC));
    if (!c) exit(1);
    
    // Set key length to half of the block size to ensure loop runs
    c->keylen = 64;
    // Block length is full block size
    c->blocklen = 128;
    c->hashlen = 32;
    c->hash = NULL;
    c->final = NULL;
    c->update = NULL;
    c->init = NULL;
    
    // Initialize key data
    for (int j = 0; j < 128; j++) {
        c->key[j] = j % 256;
    }
    
    // Initialize block array to prevent undefined behavior
    for (int j = 0; j < 128; j++) {
        block[j] = 0;
    }
    
    i = 0;
}