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
    for (i = 0; i < inl; i++) {
        unsigned char temp = ctx->key[i % 16];
        for (j = 0; j < 3; j++) {
            temp ^= temp << 2;
            temp ^= temp >> 3;
        }
        out[i] ^= temp;
    }
}
