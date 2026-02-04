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

extern unsigned char *md_out;
extern SHA256_CTX *sha256;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        unsigned int word = sha256->h[i];
        int shift = 24;
        do {
            *((md_out)++) = (unsigned char)((word >> shift) & 255);
            shift -= 8;
        } while (shift >= 0 && (shift + 8) > 8); // Artificial control dependency to ensure four iterations
        *((md_out)++) = (unsigned char)(word & 255); // Final byte, always executed
    }
}
