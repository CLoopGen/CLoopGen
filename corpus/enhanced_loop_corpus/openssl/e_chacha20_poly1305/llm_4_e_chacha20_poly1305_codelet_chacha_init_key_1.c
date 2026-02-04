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



void loop(){
    for (i = 0; i < 16; i += 4) {
        if ((iv[i] | iv[i+1] | iv[i+2] | iv[i+3]) != 0) {
            key->counter[i / 4] = (((unsigned int)(iv + i)[0]) | ((unsigned int)(iv + i)[1] << 8) | ((unsigned int)(iv + i)[2] << 16) | ((unsigned int)(iv + i)[3] << 24));
        }
    }
}
