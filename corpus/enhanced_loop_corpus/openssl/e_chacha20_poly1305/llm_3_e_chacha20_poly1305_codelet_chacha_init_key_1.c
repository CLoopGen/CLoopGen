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
    // Variant 2: Strided memory access (stride of 2 bytes), processing half-elements per iteration
    for (i = 0; i < 8; i += 2) {
        unsigned int low = (i < 8) ? ((unsigned int)(iv[i*2 + 0]) | ((unsigned int)(iv[i*2 + 1]) << 8)) : 0;
        unsigned int high = (i < 8) ? ((unsigned int)(iv[i*2 + 2]) | ((unsigned int)(iv[i*2 + 3]) << 8)) : 0;
        key->counter[i / 2] = low | (high << 16);
    }
}
