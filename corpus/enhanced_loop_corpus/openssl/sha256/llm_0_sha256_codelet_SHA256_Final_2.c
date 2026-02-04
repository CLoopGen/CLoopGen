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
    for (nn = 0; nn < 28 / 4; nn++) {
        ll = (c)->h[nn];
        for (int shift = 24; shift >= 0; shift -= 8) {
            *(md++) = (unsigned char)((ll >> shift) & 255);
        }
    }
}
