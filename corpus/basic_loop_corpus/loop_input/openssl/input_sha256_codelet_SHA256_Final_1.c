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

static unsigned char md_buffer[1024 * 128]; // 128KB buffer
static SHA256_CTX c_instance;

void init_vars() {
    // Initialize the SHA256 context h values to non-zero for realistic test
    for (int i = 0; i < 8; i++) {
        c_instance.h[i] = 0x6a09e667 ^ (i * 0x5be0cd19);
    }
    c_instance.md_len = 32;
    c_instance.num = 0;
    c_instance.Nl = 0;
    c_instance.Nh = 0;
    for (int i = 0; i < 16; i++) {
        c_instance.data[i] = 0;
    }

    // Initialize pointers
    c = &c_instance;
    md = md_buffer;
    ll = 0;
    nn = 0;
}