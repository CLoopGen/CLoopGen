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

extern AVHMAC *c;
extern uint8_t block[128];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    block[0] = c->key[0] ^ 92;
    for (i = 1; i < c->keylen; i++) {
        block[i] = block[i-1] + (c->key[i] ^ 92) - (c->key[i-1] ^ 92);
    }
}
