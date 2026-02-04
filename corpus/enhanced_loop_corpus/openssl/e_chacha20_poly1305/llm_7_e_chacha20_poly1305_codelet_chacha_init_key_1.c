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
    unsigned int local_counter[4] = {0};
    for (i = 0; i < 16; i += 4) {
        local_counter[i / 4] = (((unsigned int)(iv + i)[0]) | ((unsigned int)(iv + i)[1] << 8) | ((unsigned int)(iv + i)[2] << 16) | ((unsigned int)(iv + i)[3] << 24));
        key->counter[i / 4] = local_counter[i / 4];
    }
    key->partial_len = (key->counter[0] + key->counter[1] + key->counter[2] + key->counter[3]) & 0xFF;
}
