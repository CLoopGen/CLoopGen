#include <stdio.h>
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

static unsigned char md_storage[1024 * 128]; // 128KB to ensure ~0.01s runtime
static SHA512_CTX c_instance;

void init_vars() {
    md = md_storage;
    c = &c_instance;

    for (int i = 0; i < 8; i++) {
        c->h[i] = 0xdeadbeefdeadbeefULL ^ (unsigned long long)i;
    }

    c->Nl = 0;
    c->Nh = 0;
    c->num = 0;
    c->md_len = 64;
}