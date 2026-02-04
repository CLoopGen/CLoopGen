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

extern unsigned char *md;
extern SHA512_CTX *c;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (n = 0; n < 64 / 8; n++) {
        unsigned long long t = c->h[n];
        // Change memory access pattern to strided: write every 2nd byte first, then fill in
        md[0] = (unsigned char)(t >> 56);
        md[2] = (unsigned char)(t >> 48);
        md[4] = (unsigned char)(t >> 40);
        md[6] = (unsigned char)(t >> 32);
        md[1] = (unsigned char)(t >> 24);
        md[3] = (unsigned char)(t >> 16);
        md[5] = (unsigned char)(t >> 8);
        md[7] = (unsigned char)(t);
        md += 8;
    }
}
