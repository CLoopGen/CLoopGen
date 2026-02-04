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
    // Variant 2: Strided memory access with stride of 8, processing alternating segments
    for (i = 0; i < 16; i += 8) {
        // First segment at current stride
        key->key.d[i / 8 * 2 + 0] = (
            ((unsigned int)(user_key + i)[0]) | 
            ((unsigned int)(user_key + i)[1] << 8) | 
            ((unsigned int)(user_key + i)[2] << 16) | 
            ((unsigned int)(user_key + i)[3] << 24)
        );
        // Second segment at offset +4 within the same stride
        key->key.d[i / 8 * 2 + 1] = (
            ((unsigned int)(user_key + i + 4)[0]) | 
            ((unsigned int)(user_key + i + 4)[1] << 8) | 
            ((unsigned int)(user_key + i + 4)[2] << 16) | 
            ((unsigned int)(user_key + i + 4)[3] << 24)
        );
    }
}
