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
    size_t stride = 8;
    size_t j;

    for (j = 0; j < stride; j++) {
        for (i = j; i < inl; i += stride) {
            out[i] ^= ctx->key[i % 16];
        }
    }
}
