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



void loop(){
    for (n = 0; n < 64 / 8; n++) {
        unsigned long long t = c->h[n];
        unsigned char *p = md;
        p[0] = (unsigned char)(t >> 56);
        p[1] = (unsigned char)(t >> 48);
        p[2] = (unsigned char)(t >> 40);
        p[3] = (unsigned char)(t >> 32);
        p[4] = (unsigned char)(t >> 24);
        p[5] = (unsigned char)(t >> 16);
        p[6] = (unsigned char)(t >> 8);
        p[7] = (unsigned char)(t);
        md += 8;
    }
}
