#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct prov_cipher_fake_ctx_st {
    char key_name[32];
    unsigned char key[16];
} PROV_CIPHER_FAKE_CTX;

unsigned char *out;
size_t inl;
PROV_CIPHER_FAKE_CTX *ctx;
size_t i;

void init_vars() {
    inl = 512 * 1024; // 512 KB data size for ~0.01 sec runtime
    out = (unsigned char *)calloc(inl, sizeof(unsigned char));
    ctx = (PROV_CIPHER_FAKE_CTX *)malloc(sizeof(PROV_CIPHER_FAKE_CTX));

    if (!out || !ctx) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    strcpy(ctx->key_name, "test_key");
    for (int k = 0; k < 16; k++) {
        ctx->key[k] = (unsigned char)(k + 1);
    }

    for (size_t idx = 0; idx < inl; idx++) {
        out[idx] = (unsigned char)(idx & 0xFF);
    }
}