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
    for (i = 0; i < 16; i += 2) {
        unsigned long long val1 = sha512->h[i/2];
        unsigned long long val2 = (i + 1 < 8) ? sha512->h[i/2 + 1] : 0;
        *((md_out)++) = (unsigned char)((val1 >> 56) & 255);
        *((md_out)++) = (unsigned char)((val1 >> 48) & 255);
        *((md_out)++) = (unsigned char)((val1 >> 40) & 255);
        *((md_out)++) = (unsigned char)((val1 >> 32) & 255);
        if (i + 1 < 8) {
            *((md_out)++) = (unsigned char)((val2 >> 56) & 255);
            *((md_out)++) = (unsigned char)((val2 >> 48) & 255);
            *((md_out)++) = (unsigned char)((val2 >> 40) & 255);
            *((md_out)++) = (unsigned char)((val2 >> 32) & 255);
        }
        *((md_out)++) = (unsigned char)((val1 >> 24) & 255);
        *((md_out)++) = (unsigned char)((val1 >> 16) & 255);
        *((md_out)++) = (unsigned char)((val1 >> 8)  & 255);
        *((md_out)++) = (unsigned char)(val1 & 255);
        if (i + 1 < 8) {
            *((md_out)++) = (unsigned char)((val2 >> 24) & 255);
            *((md_out)++) = (unsigned char)((val2 >> 16) & 255);
            *((md_out)++) = (unsigned char)((val2 >> 8)  & 255);
            *((md_out)++) = (unsigned char)(val2 & 255);
        }
    }
}
