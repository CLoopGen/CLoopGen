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

extern unsigned char *md;
extern SHA256_CTX *c;
extern unsigned long ll;
extern unsigned int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (nn = 0; nn < 24 / 4; nn++) {
        ll = (c)->h[nn];
        unsigned int b0 = (ll >> 24) & 255;
        unsigned int b1 = (ll >> 16) & 255;
        unsigned int b2 = (ll >> 8) & 255;
        unsigned int b3 = ll & 255;
        *(((md))++) = (unsigned char)b0;
        *(((md))++) = (unsigned char)b1;
        *(((md))++) = (unsigned char)b2;
        *(((md))++) = (unsigned char)b3;
    }
}
