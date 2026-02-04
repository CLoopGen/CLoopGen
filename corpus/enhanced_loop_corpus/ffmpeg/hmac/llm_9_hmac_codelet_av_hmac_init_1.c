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
extern int i;
extern uint8_t block[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = c->keylen; i < c->blocklen; i += stride) {
        block[i] = 54;
        if (i + 1 < c->blocklen) {
            block[i + 1] = 54;
        }
    }
}
