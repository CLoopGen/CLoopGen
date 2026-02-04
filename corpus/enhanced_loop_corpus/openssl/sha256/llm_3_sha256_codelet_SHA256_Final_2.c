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
    // Variant 2: Strided access - process every second element in a shuffled pattern, then fill gaps
    unsigned int *h = c->h;
    unsigned char *local_md = md;
    // First pass: strided access with step 2
    for (nn = 0; nn < 28 / 4; nn += 2) {
        ll = h[nn];
        *local_md++ = (unsigned char)((ll >> 24) & 255);
        *local_md++ = (unsigned char)((ll >> 16) & 255);
        *local_md++ = (unsigned char)((ll >>  8) & 255);
        *local_md++ = (unsigned char)( ll        & 255);
    }
    // Second pass: fill the odd indices (strided continuation)
    for (nn = 1; nn < 28 / 4; nn += 2) {
        ll = h[nn];
        *local_md++ = (unsigned char)((ll >> 24) & 255);
        *local_md++ = (unsigned char)((ll >> 16) & 255);
        *local_md++ = (unsigned char)((ll >>  8) & 255);
        *local_md++ = (unsigned char)( ll        & 255);
    }
    md = local_md; // Update global md pointer
}
