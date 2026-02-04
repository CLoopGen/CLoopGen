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
    for (n = 0; n < 32 / 8; ++n) {
        unsigned long long t = c->h[n];
        int shift = 56;
        for (int i = 0; i < 8; ++i) {
            if (shift >= 0) {
                *(md++) = (unsigned char)(t >> shift);
            }
            shift -= 8;
        }
    }
}
