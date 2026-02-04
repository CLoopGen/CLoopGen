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
    c = (SHA256_CTX*)malloc(sizeof(SHA256_CTX));
    for (int i = 0; i < 8; i++) {
        c->h[i] = 0xdeadbeef + i;
    }
    c->Nl = 0;
    c->Nh = 0;
    c->num = 0;
    c->md_len = 32;
    
    md = (unsigned char*)malloc(1024 * 1024);
}