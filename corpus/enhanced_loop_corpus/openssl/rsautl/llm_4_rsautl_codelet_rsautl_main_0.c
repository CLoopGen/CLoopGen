#include <stdio.h>

#include <inttypes.h>

extern unsigned char *rsa_in;
extern size_t rsa_inlen;
extern size_t i;
extern unsigned char ctmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < rsa_inlen / 2; i++) {
        if (i != rsa_inlen - 1 - i) {
            ctmp = rsa_in[i];
            rsa_in[i] = rsa_in[rsa_inlen - 1 - i];
            rsa_in[rsa_inlen - 1 - i] = ctmp;
        }
    }
}
