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



void loop() {
    size_t block_size = 4;
    size_t remainder = inl % block_size;
    size_t limit = inl - remainder;

    for (i = 0; i < limit; i += block_size) {
        out[i] ^= ctx->key[i % 16];
        out[i + 1] ^= ctx->key[(i + 1) % 16];
        out[i + 2] ^= ctx->key[(i + 2) % 16];
        out[i + 3] ^= ctx->key[(i + 3) % 16];
    }

    for (; i < inl; i++) {
        out[i] ^= ctx->key[i % 16];
    }
}
