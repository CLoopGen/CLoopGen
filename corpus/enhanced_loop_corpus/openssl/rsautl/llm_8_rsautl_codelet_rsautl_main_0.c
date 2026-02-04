#include <stdio.h>

#include <inttypes.h>

extern unsigned char *rsa_in;
extern size_t rsa_inlen;
extern size_t i;
extern unsigned char ctmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < rsa_inlen; i += 2) {
        if (i >= rsa_inlen - 1 - i) break;
        ctmp = rsa_in[i];
        rsa_in[i] = rsa_in[rsa_inlen - 1 - i];
        rsa_in[rsa_inlen - 1 - i] = ctmp;
    }
}
