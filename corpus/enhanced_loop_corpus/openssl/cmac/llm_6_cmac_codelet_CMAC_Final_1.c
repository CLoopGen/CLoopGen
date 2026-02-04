#include <stdio.h>

#include <inttypes.h>

typedef struct evp_cipher_ctx_st EVP_CIPHER_CTX;

struct CMAC_CTX_st {
    EVP_CIPHER_CTX *cctx;
    unsigned char k1[32];
    unsigned char k2[32];
    unsigned char tbl[32];
    unsigned char last_block[32];
    int nlast_block;
};


typedef struct CMAC_CTX_st CMAC_CTX;

extern CMAC_CTX *ctx;
extern unsigned char *out;
extern int i;
extern int bl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp[32];
    for (i = 0; i < bl; i++)
        temp[i] = ctx->k1[i];
    for (i = 0; i < bl; i++)
        out[i] = ctx->last_block[i] ^ temp[i];
}
