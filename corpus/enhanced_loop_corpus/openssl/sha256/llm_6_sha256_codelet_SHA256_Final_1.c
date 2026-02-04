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
    unsigned int temp_h[6]; // Local copy to alter data dependencies
    for (nn = 0; nn < 24 / 4; nn++) {
        temp_h[nn] = (c)->h[nn]; // Introduce temporary storage, breaking direct RAW dependency on c->h
    }
    for (nn = 0; nn < 24 / 4; nn++) {
        ll = temp_h[nn]; // Now reading from local array instead of directly from c->h
        (void)(*(((md))++) = (unsigned char)(((ll) >> 24) & 255) , *(((md))++) = (unsigned char)(((ll) >> 16) & 255) , *(((md))++) = (unsigned char)(((ll) >> 8) & 255) , *(((md))++) = (unsigned char)(((ll)) & 255) , ll);
    }
}
