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
typedef struct evp_md_ctx_st EVP_MD_CTX;

typedef struct {
    OSSL_LIB_CTX *libctx;
    char *propq;
    RSA *rsa;
    int operation;
    unsigned int flag_sigalg : 1;
    unsigned int flag_allow_md : 1;
    unsigned int mgf1_md_set : 1;
    unsigned int flag_allow_update : 1;
    unsigned int flag_allow_final : 1;
    unsigned int flag_allow_oneshot : 1;
    EVP_MD *md;
    EVP_MD_CTX *mdctx;
    int mdnid;
    char mdname[50];
    int pad_mode;
    EVP_MD *mgf1_md;
    int mgf1_mdnid;
    char mgf1_mdname[50];
    int saltlen;
    int min_saltlen;
    unsigned char *sig;
    size_t siglen;
    unsigned char *tbuf;
} PROV_RSA_CTX;

OSSL_ITEM padding_item[256];
PROV_RSA_CTX *prsactx;
int i;
char *word;

void init_vars() {
    prsactx = (PROV_RSA_CTX *)calloc(1, sizeof(PROV_RSA_CTX));
    word = NULL;

    prsactx->pad_mode = 255;
    prsactx->sig = (unsigned char *)malloc(1024);
    prsactx->siglen = 1024;
    prsactx->tbuf = (unsigned char *)malloc(1024);
    prsactx->propq = (char *)malloc(64);
    strcpy(prsactx->propq, "default");

    for (int idx = 0; idx < 255; idx++) {
        padding_item[idx].id = idx + 1;
        padding_item[idx].ptr = malloc(32);
        sprintf((char *)padding_item[idx].ptr, "padding_method_%u", idx + 1);
    }
    padding_item[255].id = 0;
    padding_item[255].ptr = NULL;
}