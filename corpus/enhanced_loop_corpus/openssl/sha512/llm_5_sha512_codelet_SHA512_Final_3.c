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
    for (n = 0; n < 64 / 8; ++n) {
        unsigned long long t = c->h[n];
        unsigned char bytes[8];
        bytes[0] = (unsigned char)(t >> 56);
        bytes[1] = (unsigned char)(t >> 48);
        bytes[2] = (unsigned char)(t >> 40);
        bytes[3] = (unsigned char)(t >> 32);
        bytes[4] = (unsigned char)(t >> 24);
        bytes[5] = (unsigned char)(t >> 16);
        bytes[6] = (unsigned char)(t >> 8);
        bytes[7] = (unsigned char)(t);

        for (int i = 0; i < 8; ++i) {
            if (bytes[i] != 0 || i == 7) {
                *(md++) = bytes[i];
            }
        }
    }
}
