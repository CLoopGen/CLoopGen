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

extern  unsigned char iv[16];
extern EVP_CHACHA_KEY *key;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with reversed order
    unsigned char *iv_ptr = iv;
    for (i = 12; i != (unsigned int)-4; i -= 4) {
        unsigned int idx = i / 4;
        key->counter[idx] = ((unsigned int)iv_ptr[i + 0]) |
                            ((unsigned int)iv_ptr[i + 1] << 8) |
                            ((unsigned int)iv_ptr[i + 2] << 16) |
                            ((unsigned int)iv_ptr[i + 3] << 24);
    }
}
