#include <stdio.h>

#include <inttypes.h>

typedef struct SHA256state_st {
    unsigned int h[8];
    unsigned int Nl;
    unsigned int Nh;
    unsigned int data[16];
    unsigned int num;
    unsigned int md_len;
} SHA256_CTX;

extern unsigned char *md_out;
extern SHA256_CTX *sha256;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Strided memory access: process one byte position across all h[] elements first, then next byte
    for (int byte_offset = 0; byte_offset < 4; byte_offset++) {
        unsigned int shift = 24 - (byte_offset * 8);
        for (i = 0; i < 8; i++) {
            *((md_out)++) = (unsigned char)((sha256->h[i] >> shift) & 255);
        }
    }
}
