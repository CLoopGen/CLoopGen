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

extern unsigned char *md_out;
extern SHA512_CTX *sha512;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    unsigned long long val;
    for (i = 0; i < 8; i++) {
        val = sha512->h[i];
        // Introduce artificial write-after-write dependency by reassigning val in parts
        // This creates intra-loop WAW-like semantics even though it's not strictly necessary
        val = (val >> 56) & 255; *((md_out)++) = (unsigned char)val;
        val = sha512->h[i]; 
        val = (val >> 48) & 255; *((md_out)++) = (unsigned char)val;
        val = sha512->h[i]; 
        val = (val >> 40) & 255; *((md_out)++) = (unsigned char)val;
        val = sha512->h[i]; 
        val = (val >> 32) & 255; *((md_out)++) = (unsigned char)val;
        val = sha512->h[i]; 
        val = (val >> 24) & 255; *((md_out)++) = (unsigned char)val;
        val = sha512->h[i]; 
        val = (val >> 16) & 255; *((md_out)++) = (unsigned char)val;
        val = sha512->h[i]; 
        val = (val >> 8)  & 255; *((md_out)++) = (unsigned char)val;
        val = sha512->h[i]; 
        val = val & 255;        *((md_out)++) = (unsigned char)val;
    }
}
