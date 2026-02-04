#include <stdio.h>

#include <inttypes.h>

typedef struct prov_cipher_fake_ctx_st {
    char key_name[32];
    unsigned char key[16];
} PROV_CIPHER_FAKE_CTX;

extern unsigned char *out;
extern size_t inl;
extern PROV_CIPHER_FAKE_CTX *ctx;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < inl; j += 2) {
        if (j + 1 < inl) {
            out[j] ^= ctx->key[j % 16];
            out[j + 1] ^= ctx->key[(j + 1) % 16];
        } else {
            out[j] ^= ctx->key[j % 16];
        }
    }
}
