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

extern unsigned char *md_out;
extern SHA512_CTX *sha512;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled loop and sequential byte extraction
    unsigned char *out = md_out;
    for (i = 0; i < 8; i++) {
        unsigned long long value = sha512->h[i];
        *out++ = (unsigned char)((value >> 56) & 255);
        *out++ = (unsigned char)((value >> 48) & 255);
        *out++ = (unsigned char)((value >> 40) & 255);
        *out++ = (unsigned char)((value >> 32) & 255);
        *out++ = (unsigned char)((value >> 24) & 255);
        *out++ = (unsigned char)((value >> 16) & 255);
        *out++ = (unsigned char)((value >> 8)  & 255);
        *out++ = (unsigned char)(value & 255);
    }
    md_out = out;
}
