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
    size_t step = 4;
    size_t limit = (inl / step) * step;
    for (i = 0; i < limit; i += step) {
        out[i] ^= ctx->key[i % 16];
        if (i + 1 < inl) out[i + 1] ^= ctx->key[(i + 1) % 16];
        if (i + 2 < inl) out[i + 2] ^= ctx->key[(i + 2) % 16];
        if (i + 3 < inl) out[i + 3] ^= ctx->key[(i + 3) % 16];
    }
    for (; i < inl; i++) {
        out[i] ^= ctx->key[i % 16];
    }
}
