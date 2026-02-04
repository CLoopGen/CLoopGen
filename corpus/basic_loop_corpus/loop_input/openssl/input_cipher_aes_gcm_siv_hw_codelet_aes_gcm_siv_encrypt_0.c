#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;

typedef struct prov_cipher_hw_aes_gcm_siv_st {
    int (*initkey)(void *);
    int (*cipher)(void *, unsigned char *, const unsigned char *, size_t);
    int (*dup_ctx)(void *, void *);
    void (*clean_ctx)(void *);
} PROV_CIPHER_HW_AES_GCM_SIV;

typedef struct ossl_lib_ctx_st OSSL_LIB_CTX;

typedef struct ossl_provider_st OSSL_PROVIDER;

typedef unsigned long long u64;

typedef struct {
    u64 hi;
    u64 lo;
} u128;

typedef struct prov_aes_gcm_siv_ctx_st {
    EVP_CIPHER_CTX *ecb_ctx;
    const PROV_CIPHER_HW_AES_GCM_SIV *hw;
    uint8_t *aad;
    OSSL_LIB_CTX *libctx;
    OSSL_PROVIDER *provctx;
    size_t aad_len;
    size_t key_len;
    uint8_t key_gen_key[32];
    uint8_t msg_enc_key[32];
    uint8_t msg_auth_key[16];
    uint8_t tag[16];
    uint8_t user_tag[16];
    uint8_t nonce[12];
    u128 Htable[16];
    unsigned int enc : 1;
    unsigned int have_user_tag : 1;
    unsigned int generated_tag : 1;
    unsigned int used_enc : 1;
    unsigned int used_dec : 1;
    unsigned int speed : 1;
} PROV_AES_GCM_SIV_CTX;

PROV_AES_GCM_SIV_CTX *ctx;
uint8_t S_s[16];
size_t i;

void init_vars() {
    ctx = (PROV_AES_GCM_SIV_CTX *)malloc(sizeof(PROV_AES_GCM_SIV_CTX));
    if (!ctx) return;

    ctx->ecb_ctx = NULL;
    ctx->hw = NULL;
    ctx->aad = NULL;
    ctx->libctx = NULL;
    ctx->provctx = NULL;
    ctx->aad_len = 0;
    ctx->key_len = 32;
    memset(ctx->key_gen_key, 0x01, 32);
    memset(ctx->msg_enc_key, 0x02, 32);
    memset(ctx->msg_auth_key, 0x03, 16);
    memset(ctx->tag, 0x04, 16);
    memset(ctx->user_tag, 0x05, 16);
    memset(ctx->nonce, 0x06, 12);
    for (int j = 0; j < 16; j++) {
        ctx->Htable[j].hi = 0xdeadbeefULL + j;
        ctx->Htable[j].lo = 0xcafebabeULL + j;
    }
    ctx->enc = 1;
    ctx->have_user_tag = 0;
    ctx->generated_tag = 0;
    ctx->used_enc = 0;
    ctx->used_dec = 0;
    ctx->speed = 0;

    memset(S_s, 0x07, 16);
    i = 0;
}