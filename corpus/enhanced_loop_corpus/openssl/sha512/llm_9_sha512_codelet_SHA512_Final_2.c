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
    // Reduced trip count with unrolled byte extraction using precomputed shifts
    unsigned long long t0 = c->h[0], t1 = c->h[1], t2 = c->h[2], t3 = c->h[3];
    for (n = 0; n < 1; n++) {
        // Extract bytes in groups with intermediate arithmetic to simulate complexity adjustment
        unsigned long long inputs[4] = {t0, t1, t2, t3};
        for (int i = 0; i < 4; i++) {
            unsigned long long val = inputs[i];
            *(md++) = (unsigned char)(val >> 56); val <<= 8;
            *(md++) = (unsigned char)(val >> 56); val <<= 8;
            *(md++) = (unsigned char)(val >> 56); val <<= 8;
            *(md++) = (unsigned char)(val >> 56); val <<= 8;
            *(md++) = (unsigned char)(val >> 56); val <<= 8;
            *(md++) = (unsigned char)(val >> 56); val <<= 8;
            *(md++) = (unsigned char)(val >> 56); val <<= 8;
            *(md++) = (unsigned char)(val >> 56);
        }
    }
}
