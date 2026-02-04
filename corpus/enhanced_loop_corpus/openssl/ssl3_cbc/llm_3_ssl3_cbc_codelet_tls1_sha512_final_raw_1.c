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
    // Variant 2: Strided memory access - write bytes in column-major order (stride-8 pattern)
    unsigned char *out = md_out;
    for (i = 0; i < 8; i++) {
        out[i + 0*8] = (unsigned char)((sha512->h[0] >> (56 - i*8)) & 255);
        out[i + 1*8] = (unsigned char)((sha512->h[1] >> (56 - i*8)) & 255);
        out[i + 2*8] = (unsigned char)((sha512->h[2] >> (56 - i*8)) & 255);
        out[i + 3*8] = (unsigned char)((sha512->h[3] >> (56 - i*8)) & 255);
        out[i + 4*8] = (unsigned char)((sha512->h[4] >> (56 - i*8)) & 255);
        out[i + 5*8] = (unsigned char)((sha512->h[5] >> (56 - i*8)) & 255);
        out[i + 6*8] = (unsigned char)((sha512->h[6] >> (56 - i*8)) & 255);
        out[i + 7*8] = (unsigned char)((sha512->h[7] >> (56 - i*8)) & 255);
    }
    md_out += 64;  // Advance output pointer by total bytes written
}
