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
    // Variant 1: Consecutive memory access with unrolled write pattern
    // Instead of accessing c->h[nn] and writing 4 bytes via md increment, 
    // we precompute the target location and write all 4 bytes in a direct, consecutive manner.
    unsigned char *local_md = md;
    unsigned int len = (c)->md_len / 4;
    
    for (nn = 0; nn < len; nn++) {
        ll = (c)->h[nn];
        local_md[0] = (unsigned char)((ll >> 24) & 255);
        local_md[1] = (unsigned char)((ll >> 16) & 255);
        local_md[2] = (unsigned char)((ll >> 8)  & 255);
        local_md[3] = (unsigned char)(ll         & 255);
        local_md += 4;
    }
    md = local_md; // Update global md pointer
}
