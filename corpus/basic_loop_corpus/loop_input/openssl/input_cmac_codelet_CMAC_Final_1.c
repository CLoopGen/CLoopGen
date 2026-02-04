#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

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

static CMAC_CTX ctx_static;
static unsigned char out_buffer[1024 * 128]; // 128KB

CMAC_CTX *ctx = &ctx_static;
unsigned char *out = out_buffer;
int i;
int bl = 32; // Since arrays in ctx are size 32, limit loop to 32 iterations

void init_vars() {
    for (int j = 0; j < 32; j++) {
        ctx->k1[j] = (unsigned char)(j * 7 + 1);
        ctx->last_block[j] = (unsigned char)(j * 13 + 5);
    }
    memset(out, 0, sizeof(out_buffer));
}