#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

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
    c = (SHA256_CTX *)malloc(sizeof(SHA256_CTX));
    if (!c) exit(1);

    c->md_len = 32; // SHA-256 produces 32-byte (256-bit) hash

    // Initialize h values to typical SHA-256 initial constants
    c->h[0] = 0x6a09e667;
    c->h[1] = 0xbb67ae85;
    c->h[2] = 0x3c6ef372;
    c->h[3] = 0xa54ff53a;
    c->h[4] = 0x510e527f;
    c->h[5] = 0x9b05688c;
    c->h[6] = 0x1f83d9ab;
    c->h[7] = 0x5be0cd19;

    c->Nl = 0;
    c->Nh = 0;
    c->num = 0;

    // Allocate output buffer: ensure it's large enough for the loop and extra space
    // The loop runs md_len/4 times, each writing 4 bytes -> total 32 bytes written
    // But we allocate more to allow safe pointer arithmetic even if caller uses larger range
    md = (unsigned char *)malloc(64);
    if (!md) exit(1);
}