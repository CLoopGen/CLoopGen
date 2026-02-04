#include <stdio.h>

#include <inttypes.h>

union {
    unsigned long long d[16];
    unsigned char p[128];
};


typedef struct SHA512state_st {
    unsigned long long h[8];
    unsigned long long Nl;
    unsigned long long Nh;
    union {
        unsigned long long d[16];
        unsigned char p[128];
    } u;
    unsigned int num;
    unsigned int md_len;
} SHA512_CTX;

extern unsigned char *md;
extern SHA512_CTX *c;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - write bytes in a non-consecutive, strided pattern
    // Assume output buffer is large enough and we're writing every 2nd byte, filling odd indices
    unsigned char *local_md = md;
    for (size_t n = 0; n < 48 / 8; n++) {
        unsigned long long t = c->h[n];
        // Writing with stride of 2, starting at index 1 (odd positions)
        local_md[1] = (unsigned char)(t >> 56);
        local_md[3] = (unsigned char)(t >> 48);
        local_md[5] = (unsigned char)(t >> 40);
        local_md[7] = (unsigned char)(t >> 32);
        local_md[9] = (unsigned char)(t >> 24);
        local_md[11] = (unsigned char)(t >> 16);
        local_md[13] = (unsigned char)(t >> 8);
        local_md[15] = (unsigned char)(t);
        local_md += 16; // Advance by stride block size
    }
    md = local_md; // Update global pointer to reflect new position
}
