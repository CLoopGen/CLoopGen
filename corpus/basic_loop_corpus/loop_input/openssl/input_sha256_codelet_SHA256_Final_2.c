#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct SHA256state_st {
    unsigned int h[8];
    unsigned int Nl;
    unsigned int Nh;
    unsigned int data[16];
    unsigned int num;
    unsigned int md_len;
} SHA256_CTX;

unsigned char *md;
SHA256_CTX *c;
unsigned long ll;
unsigned int nn;

void init_vars() {
    c = (SHA256_CTX *)aligned_alloc(32, sizeof(SHA256_CTX));
    memset(c, 0, sizeof(SHA256_CTX));
    
    for (int i = 0; i < 8; i++) {
        c->h[i] = 0xdeadbeefU ^ (i * 0x9e3779b9U);
    }
    c->Nl = 0xdeadbeefU;
    c->Nh = 0xabcdef01U;
    c->num = 0;
    c->md_len = 32;
    for (int i = 0; i < 16; i++) {
        c->data[i] = 0xfeedfaceU ^ (i * 0x12345678U);
    }

    size_t output_size = 1024 * 1024;
    unsigned char *md_base = (unsigned char *)aligned_alloc(32, output_size);
    md = md_base;
}