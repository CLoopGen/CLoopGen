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
    unsigned int idx = 0;
    for (i = 0; i < 8; i++) {
        unsigned long long word = sha512->h[i];
        md_out[idx + 0] = (unsigned char)((word >> 56) & 255);
        md_out[idx + 1] = (unsigned char)((word >> 48) & 255);
        md_out[idx + 2] = (unsigned char)((word >> 40) & 255);
        md_out[idx + 3] = (unsigned char)((word >> 32) & 255);
        md_out[idx + 4] = (unsigned char)((word >> 24) & 255);
        md_out[idx + 5] = (unsigned char)((word >> 16) & 255);
        md_out[idx + 6] = (unsigned char)((word >> 8)  & 255);
        md_out[idx + 7] = (unsigned char)(word         & 255);
        idx += 8;
    }
    md_out += 64; // Advance md_out pointer by total bytes written (8 words * 8 bytes)
}
