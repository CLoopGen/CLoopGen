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
    unsigned long long t_buffer[6]; // Preload h values to alter dependency flow
    for (n = 0; n < 48 / 8; n++) {
        t_buffer[n] = c->h[n];
    }
    for (n = 0; n < 48 / 8; n++) {
        unsigned long long t = t_buffer[n]; // Break direct dependence on memory access in c->h
        *(md++) = (unsigned char)(t >> 56);
        *(md++) = (unsigned char)(t >> 48);
        *(md++) = (unsigned char)(t >> 40);
        *(md++) = (unsigned char)(t >> 32);
        *(md++) = (unsigned char)(t >> 24);
        *(md++) = (unsigned char)(t >> 16);
        *(md++) = (unsigned char)(t >> 8);
        *(md++) = (unsigned char)(t);
    }
}
