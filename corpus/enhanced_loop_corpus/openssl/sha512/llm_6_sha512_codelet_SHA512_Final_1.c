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
    unsigned long long t0, t1, t2, t3;
    for (n = 0; n < 32 / 8; n += 4) {
        t0 = c->h[n + 0];
        t1 = c->h[n + 1];
        t2 = c->h[n + 2];
        t3 = c->h[n + 3];

        *(md++) = (unsigned char)(t0 >> 56);
        *(md++) = (unsigned char)(t0 >> 48);
        *(md++) = (unsigned char)(t0 >> 40);
        *(md++) = (unsigned char)(t0 >> 32);
        *(md++) = (unsigned char)(t0 >> 24);
        *(md++) = (unsigned char)(t0 >> 16);
        *(md++) = (unsigned char)(t0 >> 8);
        *(md++) = (unsigned char)(t0);

        *(md++) = (unsigned char)(t1 >> 56);
        *(md++) = (unsigned char)(t1 >> 48);
        *(md++) = (unsigned char)(t1 >> 40);
        *(md++) = (unsigned char)(t1 >> 32);
        *(md++) = (unsigned char)(t1 >> 24);
        *(md++) = (unsigned char)(t1 >> 16);
        *(md++) = (unsigned char)(t1 >> 8);
        *(md++) = (unsigned char)(t1);

        *(md++) = (unsigned char)(t2 >> 56);
        *(md++) = (unsigned char)(t2 >> 48);
        *(md++) = (unsigned char)(t2 >> 40);
        *(md++) = (unsigned char)(t2 >> 32);
        *(md++) = (unsigned char)(t2 >> 24);
        *(md++) = (unsigned char)(t2 >> 16);
        *(md++) = (unsigned char)(t2 >> 8);
        *(md++) = (unsigned char)(t2);

        *(md++) = (unsigned char)(t3 >> 56);
        *(md++) = (unsigned char)(t3 >> 48);
        *(md++) = (unsigned char)(t3 >> 40);
        *(md++) = (unsigned char)(t3 >> 32);
        *(md++) = (unsigned char)(t3 >> 24);
        *(md++) = (unsigned char)(t3 >> 16);
        *(md++) = (unsigned char)(t3 >> 8);
        *(md++) = (unsigned char)(t3);
    }
}
