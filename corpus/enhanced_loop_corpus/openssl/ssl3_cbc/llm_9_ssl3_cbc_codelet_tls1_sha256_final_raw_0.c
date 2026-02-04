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
    for (i = 7; i < 8 && i >= 0; i--) {
        unsigned int val = sha256->h[i];
        unsigned char bytes[4];
        bytes[0] = (unsigned char)((val >> 24) & 255);
        bytes[1] = (unsigned char)((val >> 16) & 255);
        bytes[2] = (unsigned char)((val >> 8) & 255);
        bytes[3] = (unsigned char)(val & 255);
        
        for (int j = 0; j < 4; j++) {
            *(md_out++) = bytes[j];
        }
    }
}
