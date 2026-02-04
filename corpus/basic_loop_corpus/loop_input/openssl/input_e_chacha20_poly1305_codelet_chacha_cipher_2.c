#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uintmax_t ossl_uintmax_t;

union {
    double align;
    ossl_uintmax_t align_int;
    void *align_ptr;
    unsigned int d[8];
};

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

unsigned char *out;
unsigned char *inp;
EVP_CHACHA_KEY *key;
unsigned int n;
unsigned int rem;

void init_vars() {
    const size_t data_size = 131072; // 128KB, targets ~0.01 sec on modern CPU

    out = (unsigned char *)malloc(data_size);
    inp = (unsigned char *)malloc(data_size);
    key = (EVP_CHACHA_KEY *)malloc(sizeof(EVP_CHACHA_KEY));

    if (!out || !inp || !key) {
        // Ensure allocation succeeded to prevent SIGSEGV
        exit(1);
    }

    memset(out, 0, data_size);
    for (size_t i = 0; i < data_size; ++i) {
        inp[i] = (unsigned char)(i & 0xFF);
    }
    for (int i = 0; i < 64; ++i) {
        key->buf[i] = (unsigned char)((i * 3) & 0xFF);
    }

    n = 0;
    rem = 64; // Must not exceed min of inp/out length and key->buf size (64)
}