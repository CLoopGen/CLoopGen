#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct ossl_lib_ctx_st OSSL_LIB_CTX;

typedef struct {
    uint16_t kem_id;
    uint16_t kdf_id;
    uint16_t aead_id;
} OSSL_HPKE_SUITE;

typedef struct {
    uint16_t kem_id;
    const char *keytype;
    const char *groupname;
    const char *mdname;
    size_t Nsecret;
    size_t Nenc;
    size_t Npk;
    size_t Nsk;
    uint8_t bitmask;
} OSSL_HPKE_KEM_INFO;

typedef struct {
    uint16_t kdf_id;
    const char *mdname;
    size_t Nh;
} OSSL_HPKE_KDF_INFO;

typedef struct {
    uint16_t aead_id;
    const char *name;
    size_t taglen;
    size_t Nk;
    size_t Nn;
} OSSL_HPKE_AEAD_INFO;

typedef struct evp_cipher_st EVP_CIPHER;

typedef struct evp_pkey_st EVP_PKEY;

struct ossl_hpke_ctx_st {
    OSSL_LIB_CTX *libctx;
    char *propq;
    int mode;
    OSSL_HPKE_SUITE suite;
    const OSSL_HPKE_KEM_INFO *kem_info;
    const OSSL_HPKE_KDF_INFO *kdf_info;
    const OSSL_HPKE_AEAD_INFO *aead_info;
    EVP_CIPHER *aead_ciph;
    int role;
    uint64_t seq;
    unsigned char *shared_secret;
    size_t shared_secretlen;
    unsigned char *key;
    size_t keylen;
    unsigned char *nonce;
    size_t noncelen;
    unsigned char *exportersec;
    size_t exporterseclen;
    char *pskid;
    unsigned char *psk;
    size_t psklen;
    EVP_PKEY *authpriv;
    unsigned char *authpub;
    size_t authpublen;
    unsigned char *ikme;
    size_t ikmelen;
};

typedef struct ossl_hpke_ctx_st OSSL_HPKE_CTX;

OSSL_HPKE_CTX *ctx;
unsigned char *buf;
size_t blen;
size_t i;

void init_vars() {
    blen = 512 * 1024; // 512 KB data size for ~0.01 sec runtime on modern CPU

    buf = (unsigned char *)malloc(blen);
    if (!buf) exit(1);

    ctx = (OSSL_HPKE_CTX *)malloc(sizeof(OSSL_HPKE_CTX));
    if (!ctx) exit(1);

    ctx->nonce = (unsigned char *)malloc(blen);
    if (!ctx->nonce) exit(1);
    ctx->noncelen = blen;

    for (size_t j = 0; j < blen; j++) {
        buf[j] = (unsigned char)(j & 0xFF);
        ctx->nonce[j] = (unsigned char)((j + 1) & 0xFF);
    }
}