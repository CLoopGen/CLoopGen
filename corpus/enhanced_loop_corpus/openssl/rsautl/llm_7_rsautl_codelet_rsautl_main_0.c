#include <stdio.h>

#include <inttypes.h>

extern unsigned char *rsa_in;
extern size_t rsa_inlen;
extern size_t i;
extern unsigned char ctmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t mid = rsa_inlen / 2;
    size_t j;
    for (i = 0; i < mid; i++) {
        j = rsa_inlen - 1 - i;
        ctmp = rsa_in[i] ^ rsa_in[j];
        rsa_in[i] = rsa_in[i] ^ ctmp;
        rsa_in[j] = rsa_in[j] ^ ctmp;
    }
}
