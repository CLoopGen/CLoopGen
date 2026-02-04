#include <stdio.h>

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

extern unsigned char *secret;
extern PROV_XORKEMKEX_CTX *pxorctx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i += 4) {
        secret[i]     = pxorctx->key->privkey[i]     ^ pxorctx->peerkey->pubkey[i];
        secret[i + 1] = pxorctx->key->privkey[i + 1] ^ pxorctx->peerkey->pubkey[i + 1];
        secret[i + 2] = pxorctx->key->privkey[i + 2] ^ pxorctx->peerkey->pubkey[i + 2];
        secret[i + 3] = pxorctx->key->privkey[i + 3] ^ pxorctx->peerkey->pubkey[i + 3];
    }
}
