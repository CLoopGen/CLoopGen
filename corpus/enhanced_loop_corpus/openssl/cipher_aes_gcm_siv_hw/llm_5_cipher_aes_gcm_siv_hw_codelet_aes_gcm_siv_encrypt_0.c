#include <stdio.h>

#include <inttypes.h>

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

extern PROV_AES_GCM_SIV_CTX *ctx;
extern uint8_t S_s[16];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 12; ++i) {
        S_s[i] ^= (i % 2 == 0) ? ctx->nonce[i] : 0;
    }
}
