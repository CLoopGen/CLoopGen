#include <stdio.h>

#include <inttypes.h>

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

extern unsigned char *out;
extern  unsigned char *inp;
extern EVP_CHACHA_KEY *key;
extern unsigned int n;
extern unsigned int rem;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // This variant accesses elements at even indices first, then handles odd if needed
    unsigned int i;
    for (i = 0; i < rem - 1; i += 2) {
        out[i]     = inp[i]     ^ key->buf[i];
        out[i + 1] = inp[i + 1] ^ key->buf[i + 1];
    }
    // Handle remaining element if rem is odd
    if (i < rem) {
        out[i] = inp[i] ^ key->buf[i];
    }
}
