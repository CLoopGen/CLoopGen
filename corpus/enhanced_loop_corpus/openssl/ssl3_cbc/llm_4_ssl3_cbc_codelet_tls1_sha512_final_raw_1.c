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
    for (i = 0; i < 8; i++) {
        unsigned long long val = sha512->h[i];
        if ((i & 1) == 0) {
            *((md_out)++) = (unsigned char)((val >> 56) & 255);
            *((md_out)++) = (unsigned char)((val >> 48) & 255);
            *((md_out)++) = (unsigned char)((val >> 40) & 255);
            *((md_out)++) = (unsigned char)((val >> 32) & 255);
            *((md_out)++) = (unsigned char)((val >> 24) & 255);
            *((md_out)++) = (unsigned char)((val >> 16) & 255);
            *((md_out)++) = (unsigned char)((val >> 8)  & 255);
            *((md_out)++) = (unsigned char)(val & 255);
        } else {
            *((md_out)++) = (unsigned char)((val >> 56) & 255);
            *((md_out)++) = (unsigned char)((val >> 48) & 255);
            *((md_out)++) = (unsigned char)((val >> 40) & 255);
            *((md_out)++) = (unsigned char)((val >> 32) & 255);
            *((md_out)++) = (unsigned char)((val >> 24) & 255);
            *((md_out)++) = (unsigned char)((val >> 16) & 255);
            *((md_out)++) = (unsigned char)((val >> 8)  & 255);
            *((md_out)++) = (unsigned char)(val & 255);
        }
    }
}
