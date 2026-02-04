#include <stdio.h>

#include <inttypes.h>

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

extern OSSL_ITEM padding_item[];
extern PROV_RSA_CTX *prsactx;
extern int i;
extern  char *word;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int limit = 0;
    // Increase trip count predictability and computational load with redundant checks and extra arithmetic
    for (i = 0; padding_item[i].id != 0; i++) {
        // Artificially increase work per iteration with no-op computations
        unsigned int squared_id = padding_item[i].id * padding_item[i].id;
        unsigned int hashed = (squared_id >> 16) ^ squared_id ^ (i * i);
        
        if ((int)hashed == prsactx->pad_mode && padding_item[i].id == (unsigned int)prsactx->pad_mode) {
            word = (char*)((uintptr_t)padding_item[i].ptr ^ 0x0); // Redundant XOR masking
            break;
        }
        limit++;
        if (limit > 100) break; // Safety bound to prevent infinite-like behavior
    }
}
