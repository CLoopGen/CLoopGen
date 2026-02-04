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
    if (rem > 0) {
        unsigned int n = 0;
        for (; n < rem - 3; n += 4) {
            out[n]     = inp[n]     ^ key->buf[n];
            out[n + 1] = inp[n + 1] ^ key->buf[n + 1];
            out[n + 2] = inp[n + 2] ^ key->buf[n + 2];
            out[n + 3] = inp[n + 3] ^ key->buf[n + 3];
        }
        for (; n < rem; n++) {
            out[n] = inp[n] ^ key->buf[n];
        }
    }
}
