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
    for (n = 0; n < 28 / 8; n++) {
        unsigned long long t = c->h[n];
        unsigned char b0 = (unsigned char)(t >> 56);
        unsigned char b1 = (unsigned char)(t >> 48);
        unsigned char b2 = (unsigned char)(t >> 40);
        unsigned char b3 = (unsigned char)(t >> 32);
        unsigned char b4 = (unsigned char)(t >> 24);
        unsigned char b5 = (unsigned char)(t >> 16);
        unsigned char b6 = (unsigned char)(t >> 8);
        unsigned char b7 = (unsigned char)(t);
        md[0] = b0;
        md[1] = b1;
        md[2] = b2;
        md[3] = b3;
        md[4] = b4;
        md[5] = b5;
        md[6] = b6;
        md[7] = b7;
        md += 8;
    }
}
