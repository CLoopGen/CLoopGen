#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

CMAC_CTX *ctx;
unsigned char *out;
int i;
int bl;

void init_vars() {
    // Allocate and initialize CMAC_CTX
    ctx = (CMAC_CTX*)malloc(sizeof(CMAC_CTX));
    if (!ctx) return;

    // Initialize k2 and last_block arrays with non-zero test data
    for (int j = 0; j < 32; j++) {
        ctx->k2[j] = (unsigned char)(j * 7 + 1);
        ctx->last_block[j] = (unsigned char)(j * 11 + 5);
    }
    ctx->nlast_block = 32;  // valid bytes in last_block

    // Set block length to 32 to match array sizes
    bl = 32;

    // Allocate output buffer of size 32
    out = (unsigned char*)malloc(bl * sizeof(unsigned char));
    if (!out) {
        free(ctx);
        return;
    }

    // Initialize output memory to zero
    memset(out, 0, bl);
}