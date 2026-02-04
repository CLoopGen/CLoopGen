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
    if (inl > 0) {
        size_t block_count = inl / 16;
        size_t remainder = inl % 16;
        size_t i_block;

        for (i_block = 0; i_block < block_count; i_block++) {
            for (i = i_block * 16; i < (i_block + 1) * 16; i++) {
                out[i] ^= ctx->key[i % 16];
            }
        }

        for (i = block_count * 16; i < inl; i++) {
            out[i] ^= ctx->key[i % 16];
        }
    }
}
