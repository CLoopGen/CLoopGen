#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct evp_Encode_Ctx_st EVP_ENCODE_CTX;

typedef struct b64_struct {
    int buf_len;
    int buf_off;
    int tmp_len;
    int tmp_nl;
    int encode;
    int start;
    int cont;
    EVP_ENCODE_CTX *base64;
    unsigned char buf[1502];
    unsigned char tmp[1024];
} BIO_B64_CTX;

int ii;
int n = 1024;
BIO_B64_CTX *ctx;
unsigned char *p;

void init_vars() {
    ctx = (BIO_B64_CTX*)malloc(sizeof(BIO_B64_CTX));
    p = (unsigned char*)malloc(n * sizeof(unsigned char));
    for (int i = 0; i < n; i++) {
        p[i] = (unsigned char)(i & 0xFF);
    }
}