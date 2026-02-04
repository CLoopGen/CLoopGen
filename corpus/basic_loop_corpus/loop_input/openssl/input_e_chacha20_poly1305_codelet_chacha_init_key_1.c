#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uintmax_t ossl_uintmax_t;

typedef struct {
    union {
        double align;
        ossl_uintmax_t align_int;
        void *align_ptr;
        unsigned int d[8];
    } key;
    unsigned int counter[4];
    unsigned char buf[64];
    unsigned int partial_len;
} EVP_CHACHA_KEY;

unsigned char iv[16];
EVP_CHACHA_KEY *key;
unsigned int i;

void init_vars() {
    key = (EVP_CHACHA_KEY*)malloc(sizeof(EVP_CHACHA_KEY));
    if (key == NULL) {
        exit(1);
    }
    for (int j = 0; j < 16; j++) {
        iv[j] = (unsigned char)(j & 0xFF);
    }
    key->partial_len = 0;
}