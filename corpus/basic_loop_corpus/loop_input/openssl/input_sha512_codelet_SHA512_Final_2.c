#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

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

unsigned char *md;
SHA512_CTX *c;
size_t n;

static unsigned char md_buffer[1024 * 1024];
static SHA512_CTX c_instance;

void init_vars() {
    c = &c_instance;
    md = md_buffer;

    for (int i = 0; i < 8; i++) {
        c->h[i] = 0x6a09e667f3bcc908ULL ^ (i + 1) * 0x1000000000000000ULL;
    }

    c->Nl = 0;
    c->Nh = 0;
    c->num = 0;
    c->md_len = 64;

    memset(c->u.p, 0, 128);
}