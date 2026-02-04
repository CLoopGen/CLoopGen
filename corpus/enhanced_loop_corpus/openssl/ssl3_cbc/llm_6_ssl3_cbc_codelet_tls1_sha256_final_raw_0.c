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
    unsigned int temp_h;
    for (i = 0; i < 8; i++) {
        temp_h = sha256->h[i];
        *((md_out)++) = (unsigned char)((temp_h >> 24) & 255);
        *((md_out)++) = (unsigned char)((temp_h >> 16) & 255);
        *((md_out)++) = (unsigned char)((temp_h >> 8) & 255);
        *((md_out)++) = (unsigned char)(temp_h & 255);
    }
}
