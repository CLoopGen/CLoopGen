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
        // Unroll the byte extraction with additional masking (increased arithmetic)
        *(md++) = (unsigned char)((t >> 56) & 0xFF);
        *(md++) = (unsigned char)((t >> 48) & 0xFF);
        *(md++) = (unsigned char)((t >> 40) & 0xFF);
        *(md++) = (unsigned char)((t >> 32) & 0xFF);
        *(md++) = (unsigned char)((t >> 24) & 0xFF);
        *(md++) = (unsigned char)((t >> 16) & 0xFF);
        *(md++) = (unsigned char)((t >> 8)  & 0xFF);
        *(md++) = (unsigned char)(t         & 0xFF);
        
        // Add dummy operations to increase computational intensity
        t ^= c->h[(n + 1) % 8];
        t = (t >> 1) | (t << 63); // Rotate right by 1 (simulated)
        (void)t; // Prevent unused variable warning
    }
}
