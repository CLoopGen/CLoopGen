#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

union {
    unsigned long long d[16];
    unsigned char p[128];
};

typedef struct SHA512state_st {
    unsigned long long h[8];
    unsigned long long Nl;
    unsigned long long Nh;
    union {
        unsigned long long d[16];
        unsigned char p[128];
    } u;
    unsigned int num;
    unsigned int md_len;
} SHA512_CTX;

unsigned char *md_out;
SHA512_CTX *sha512;
unsigned int i;

void init_vars() {
    sha512 = (SHA512_CTX *)malloc(sizeof(SHA512_CTX));
    for (int j = 0; j < 8; ++j) {
        sha512->h[j] = 0x100000001ULL * (j + 1);
    }
    sha512->Nl = 0;
    sha512->Nh = 0;
    sha512->num = 0;
    sha512->md_len = 64;

    md_out = (unsigned char *)malloc(1024 * 128);
    if (!md_out) {
        exit(1);
    }
}