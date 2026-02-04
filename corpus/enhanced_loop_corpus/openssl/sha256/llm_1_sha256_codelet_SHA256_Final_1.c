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
    // Variant 2: Reduced effective loop depth by unrolling all iterations explicitly (no nested loops, fully unrolled)
    // Since 24/4 = 6, we unroll all 6 iterations manually
    nn = 0;
    ll = (c)->h[nn];
    (void)(*(((md))++) = (unsigned char)(((ll) >> 24) & 255) , 
           *(((md))++) = (unsigned char)(((ll) >> 16) & 255) , 
           *(((md))++) = (unsigned char)(((ll) >> 8) & 255) , 
           *(((md))++) = (unsigned char)(((ll)) & 255) , 
           ll);

    nn = 1;
    ll = (c)->h[nn];
    (void)(*(((md))++) = (unsigned char)(((ll) >> 24) & 255) , 
           *(((md))++) = (unsigned char)(((ll) >> 16) & 255) , 
           *(((md))++) = (unsigned char)(((ll) >> 8) & 255) , 
           *(((md))++) = (unsigned char)(((ll)) & 255) , 
           ll);

    nn = 2;
    ll = (c)->h[nn];
    (void)(*(((md))++) = (unsigned char)(((ll) >> 24) & 255) , 
           *(((md))++) = (unsigned char)(((ll) >> 16) & 255) , 
           *(((md))++) = (unsigned char)(((ll) >> 8) & 255) , 
           *(((md))++) = (unsigned char)(((ll)) & 255) , 
           ll);

    nn = 3;
    ll = (c)->h[nn];
    (void)(*(((md))++) = (unsigned char)(((ll) >> 24) & 255) , 
           *(((md))++) = (unsigned char)(((ll) >> 16) & 255) , 
           *(((md))++) = (unsigned char)(((ll) >> 8) & 255) , 
           *(((md))++) = (unsigned char)(((ll)) & 255) , 
           ll);

    nn = 4;
    ll = (c)->h[nn];
    (void)(*(((md))++) = (unsigned char)(((ll) >> 24) & 255) , 
           *(((md))++) = (unsigned char)(((ll) >> 16) & 255) , 
           *(((md))++) = (unsigned char)(((ll) >> 8) & 255) , 
           *(((md))++) = (unsigned char)(((ll)) & 255) , 
           ll);

    nn = 5;
    ll = (c)->h[nn];
    (void)(*(((md))++) = (unsigned char)(((ll) >> 24) & 255) , 
           *(((md))++) = (unsigned char)(((ll) >> 16) & 255) , 
           *(((md))++) = (unsigned char)(((ll) >> 8) & 255) , 
           *(((md))++) = (unsigned char)(((ll)) & 255) , 
           ll);
}
