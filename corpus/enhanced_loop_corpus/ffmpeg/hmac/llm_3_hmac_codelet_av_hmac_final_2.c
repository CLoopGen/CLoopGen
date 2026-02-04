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



void loop() {
    int index[128];
    // Create an indirect access pattern: reverse order
    int n = c->keylen;
    for (int j = 0; j < n; j++) {
        index[j] = n - 1 - j;
    }
    // Use the indirect indices to access key and assign to block
    for (int j = 0; j < n; j++) {
        int idx = index[j];
        block[idx] = c->key[idx] ^ 92;
    }
}
