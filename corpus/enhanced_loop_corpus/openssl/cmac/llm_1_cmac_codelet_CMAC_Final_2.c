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
    int outer = bl > 16 ? 2 : 1;
    int chunk, start;
    for (chunk = 0; chunk < outer; chunk++) {
        start = chunk * 16;
        for (i = start; i < bl && i < start + 16; i++)
            out[i] = ctx->last_block[i] ^ ctx->k2[i];
    }
}
