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
    // Variant 1: Consecutive memory access with unrolled writes using pointer arithmetic
    unsigned char *local_md = md;
    unsigned int *h = c->h;
    for (nn = 0; nn < 28 / 4; nn++) {
        ll = h[nn];
        *local_md++ = (unsigned char)((ll >> 24) & 255);
        *local_md++ = (unsigned char)((ll >> 16) & 255);
        *local_md++ = (unsigned char)((ll >>  8) & 255);
        *local_md++ = (unsigned char)( ll        & 255);
    }
    md = local_md; // Update global md pointer
}
