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

extern  unsigned char user_key[32];
extern EVP_CHACHA_KEY *key;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1; ++i) {
        for (int j = 0; j < 8; ++j) {
            key->key.d[j] = (((unsigned int)(user_key[j*4+0])      ) |
                             ((unsigned int)(user_key[j*4+1]) <<  8) |
                             ((unsigned int)(user_key[j*4+2]) << 16) |
                             ((unsigned int)(user_key[j*4+3]) << 24));
        }
    }
}
