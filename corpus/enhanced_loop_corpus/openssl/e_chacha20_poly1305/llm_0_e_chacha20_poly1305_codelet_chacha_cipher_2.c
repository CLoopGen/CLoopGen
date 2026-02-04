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
    for (unsigned int i = 0; i < rem; i += 8) {
        for (unsigned int j = 0; j < 8; j++) {
            unsigned int n = i + j;
            if (n >= rem) break;
            out[n] = inp[n] ^ key->buf[n];
        }
    }
}
