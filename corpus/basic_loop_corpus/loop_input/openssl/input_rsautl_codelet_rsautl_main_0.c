#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *rsa_in;
size_t rsa_inlen;
size_t i;
unsigned char ctmp;

void init_vars() {
    rsa_inlen = 512 * 1024; // 512 KB to target ~0.01 sec runtime
    rsa_in = (unsigned char*)malloc(rsa_inlen);
    if (!rsa_in) {
        rsa_inlen = 0;
        return;
    }
    for (size_t idx = 0; idx < rsa_inlen; idx++) {
        rsa_in[idx] = (unsigned char)(idx & 0xFF);
    }
}