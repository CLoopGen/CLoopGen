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
    for (size_t n = 0; n < 8; n += 2) {
        unsigned long long t0 = c->h[n];
        *(md++) = (unsigned char)(t0 >> 56);
        *(md++) = (unsigned char)(t0 >> 48);
        *(md++) = (unsigned char)(t0 >> 40);
        *(md++) = (unsigned char)(t0 >> 32);
        *(md++) = (unsigned char)(t0 >> 24);
        *(md++) = (unsigned char)(t0 >> 16);
        *(md++) = (unsigned char)(t0 >> 8);
        *(md++) = (unsigned char)(t0);

        if (n + 1 < 64 / 8) {
            unsigned long long t1 = c->h[n + 1];
            *(md++) = (unsigned char)(t1 >> 56);
            *(md++) = (unsigned char)(t1 >> 48);
            *(md++) = (unsigned char)(t1 >> 40);
            *(md++) = (unsigned char)(t1 >> 32);
            *(md++) = (unsigned char)(t1 >> 24);
            *(md++) = (unsigned char)(t1 >> 16);
            *(md++) = (unsigned char)(t1 >> 8);
            *(md++) = (unsigned char)(t1);
        }
    }
}
