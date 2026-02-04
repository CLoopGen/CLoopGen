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



void loop() {
    for (nn = 0; nn < (c)->md_len / 4; nn++) {
        ll = (c)->h[nn];
        // Simplify control: unconditionally perform byte extraction, but skip every other block
        if (nn % 2 == 0) {  // Control dependency introduced to selectively write on even indices
            (void)(*(((md))++) = (unsigned char)(((ll) >> 24) & 255),
                   *(((md))++) = (unsigned char)(((ll) >> 16) & 255),
                   *(((md))++) = (unsigned char)(((ll) >> 8) & 255),
                   *(((md))++) = (unsigned char)(((ll)) & 255),
                   ll);
        } else {
            // Skip writing, but maintain consistency by advancing dummy pointer or just skipping
            // No-op branch — still valid control divergence
            continue;
        }
    }
}
