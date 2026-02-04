#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct ossl_item_st {
    unsigned int id;
    void *ptr;
};

typedef struct ossl_item_st OSSL_ITEM;
typedef struct ossl_lib_ctx_st OSSL_LIB_CTX;
typedef struct rsa_st RSA;
typedef struct evp_md_st EVP_MD;

typedef struct {
    OSSL_LIB_CTX *libctx;
    RSA *rsa;
    int pad_mode;
    int operation;
    EVP_MD *oaep_md;
    EVP_MD *mgf1_md;
    unsigned char *oaep_label;
    size_t oaep_labellen;
    unsigned int client_version;
    unsigned int alt_version;
    unsigned int implicit_rejection;
} PROV_RSA_CTX;

OSSL_ITEM padding_item[4096];
PROV_RSA_CTX *prsactx;
int i;
char *word;

void init_vars() {
    // Allocate and initialize prsactx
    prsactx = (PROV_RSA_CTX *)malloc(sizeof(PROV_RSA_CTX));
    prsactx->libctx = (OSSL_LIB_CTX *)0x1000;
    prsactx->rsa = (RSA *)0x2000;
    prsactx->pad_mode = 256; // Will match padding_item[256]
    prsactx->operation = 1;
    prsactx->oaep_md = (EVP_MD *)0x3000;
    prsactx->mgf1_md = (EVP_MD *)0x4000;
    prsactx->oaep_label = NULL;
    prsactx->oaep_labellen = 0;
    prsactx->client_version = 0x100;
    prsactx->alt_version = 0x200;
    prsactx->implicit_rejection = 1;

    // Initialize word
    word = NULL;

    // Initialize padding_item array: make sure it has enough entries (~4KB items to ensure ~0.01s runtime)
    const int size = 4096;
    for (int j = 0; j < size; j++) {
        padding_item[j].id = j + 1; // ids from 1 to 4096
        padding_item[j].ptr = (void *)(0x10000 + j * 16);
    }
    // Null-terminate as per loop condition
    padding_item[size - 1].id = 0;

    // Ensure pad_mode matches one of the entries before termination
    prsactx->pad_mode = 257; // This will match padding_item[256] since id = 257
}