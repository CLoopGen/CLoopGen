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
    // Variant 1: Consecutive memory access using array indexing instead of pointer arithmetic
    unsigned char *local_md = md;
    for (size_t n = 0; n < 48 / 8; n++) {
        unsigned long long t = c->h[n];
        local_md[0] = (unsigned char)(t >> 56);
        local_md[1] = (unsigned char)(t >> 48);
        local_md[2] = (unsigned char)(t >> 40);
        local_md[3] = (unsigned char)(t >> 32);
        local_md[4] = (unsigned char)(t >> 24);
        local_md[5] = (unsigned char)(t >> 16);
        local_md[6] = (unsigned char)(t >> 8);
        local_md[7] = (unsigned char)(t);
        local_md += 8;
    }
    md = local_md; // Update global md pointer after the loop
}
