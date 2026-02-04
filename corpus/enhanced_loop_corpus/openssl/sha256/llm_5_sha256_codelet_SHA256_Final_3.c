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
    for (nn = 0; nn < 32 / 4; nn++) {
        ll = (c)->h[nn];
        if (ll != 0) {
            (void)(*(((md))++) = (unsigned char)(((ll) >> 24) & 255) , *(((md))++) = (unsigned char)(((ll) >> 16) & 255) , *(((md))++) = (unsigned char)(((ll) >> 8) & 255) , *(((md))++) = (unsigned char)(((ll)) & 255) , ll);
        } else {
            *(((md))++) = 0;
            *(((md))++) = 0;
            *(((md))++) = 0;
            *(((md))++) = 0;
        }
    }
}
