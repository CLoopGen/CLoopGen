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



void loop() {
    unsigned long long temp_h;
    for (i = 0; i < 8; i++) {
        temp_h = sha512->h[i];
        *((md_out)++) = (unsigned char)((temp_h >> 56) & 255);
        *((md_out)++) = (unsigned char)((temp_h >> 48) & 255);
        *((md_out)++) = (unsigned char)((temp_h >> 40) & 255);
        *((md_out)++) = (unsigned char)((temp_h >> 32) & 255);
        *((md_out)++) = (unsigned char)((temp_h >> 24) & 255);
        *((md_out)++) = (unsigned char)((temp_h >> 16) & 255);
        *((md_out)++) = (unsigned char)((temp_h >> 8)  & 255);
        *((md_out)++) = (unsigned char)(temp_h         & 255);
    }
}
