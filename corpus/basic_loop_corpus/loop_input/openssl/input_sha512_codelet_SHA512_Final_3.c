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

static unsigned char md_buffer[1024 * 128]; // ~128KB output buffer
static SHA512_CTX c_instance;

void init_vars() {
    // Initialize the SHA512 context
    for (int i = 0; i < 8; i++) {
        c_instance.h[i] = 0xdeadbeefdeadbeefULL ^ (unsigned long long)(i * 0x100000001);
    }
    c_instance.Nl = 0;
    c_instance.Nh = 0;
    c_instance.num = 0;
    c_instance.md_len = 64;

    // Point c to the instance
    c = &c_instance;

    // Initialize md pointer to start of buffer
    md = md_buffer;
}