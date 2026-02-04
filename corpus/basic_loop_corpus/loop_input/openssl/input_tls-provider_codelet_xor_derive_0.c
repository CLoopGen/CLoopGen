#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <inttypes.h>

typedef struct {
    _Atomic(int) val;
} CRYPTO_REF_COUNT;

typedef struct xorkey_st {
    unsigned char privkey[32];
    unsigned char pubkey[32];
    int hasprivkey;
    int haspubkey;
    char *tls_name;
    CRYPTO_REF_COUNT references;
} XORKEY;

typedef struct {
    XORKEY *key;
    XORKEY *peerkey;
    void *provctx;
} PROV_XORKEMKEX_CTX;

unsigned char *secret;
PROV_XORKEMKEX_CTX *pxorctx;
int i;

void init_vars() {
    secret = (unsigned char *)malloc(32 * sizeof(unsigned char));

    XORKEY *key_data = (XORKEY *)malloc(sizeof(XORKEY));
    XORKEY *peerkey_data = (XORKEY *)malloc(sizeof(XORKEY));

    for (int j = 0; j < 32; j++) {
        key_data->privkey[j] = (unsigned char)(j & 0xFF);
        peerkey_data->pubkey[j] = (unsigned char)((j + 16) & 0xFF);
    }

    key_data->hasprivkey = 1;
    key_data->haspubkey = 1;
    key_data->tls_name = NULL;
    key_data->references.val = 1;

    peerkey_data->hasprivkey = 1;
    peerkey_data->haspubkey = 1;
    peerkey_data->tls_name = NULL;
    peerkey_data->references.val = 1;

    pxorctx = (PROV_XORKEMKEX_CTX *)malloc(sizeof(PROV_XORKEMKEX_CTX));
    pxorctx->key = key_data;
    pxorctx->peerkey = peerkey_data;
    pxorctx->provctx = NULL;
}