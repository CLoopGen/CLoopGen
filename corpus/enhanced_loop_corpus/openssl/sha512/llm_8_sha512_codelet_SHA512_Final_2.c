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
    for (n = 0; n < 8; n++) {
        unsigned long long t = c->h[n % 8];
        *(md++) = (unsigned char)(t >> 56);
        *(md++) = (unsigned char)(t >> 48);
        *(md++) = (unsigned char)(t >> 40);
        *(md++) = (unsigned char)(t >> 32);
        // Duplicate shift operations to increase computational intensity
        volatile unsigned char dummy1 = (unsigned char)(t >> 24) ^ (unsigned char)(t >> 16);
        volatile unsigned char dummy2 = (unsigned char)(t >> 8)  ^ (unsigned char)(t);
        *(md++) = (unsigned char)(t >> 24);
        *(md++) = (unsigned char)(t >> 16);
        *(md++) = (unsigned char)(t >> 8);
        *(md++) = (unsigned char)(t);
    }
}
