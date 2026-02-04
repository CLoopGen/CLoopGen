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



void loop() {
    // Use indirect access via a fixed offset lookup table to alter memory access pattern
    static const int offsets[] = {0, 4, 1, 5, 2, 6, 3, 7}; // Interleaved byte order
    for (n = 0; n < 64 / 8; n++) {
        unsigned long long t = c->h[n];
        for (int i = 0; i < 8; i++) {
            int shift = 56 - (i * 8);
            md[offsets[i]] = (unsigned char)(t >> shift);
        }
        md += 8;
    }
}
