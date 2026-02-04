#include <stdio.h>

#include <inttypes.h>

union {
    unsigned char c[64];
    double q[8];
};


typedef struct {
    union {
        unsigned char c[64];
        double q[8];
    } H;
    unsigned char data[64];
    unsigned int bitoff;
    size_t bitlen[4];
} WHIRLPOOL_CTX;

extern WHIRLPOOL_CTX *c;
extern size_t i;
extern size_t j;
extern size_t v;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_bitlen;
    for (i = 0; i < (256 / 8) / sizeof(size_t); i++) {
        local_bitlen = c->bitlen[i];
        for (j = 0; j < sizeof(size_t); j++) {
            *p-- = (unsigned char)(local_bitlen & 255);
            local_bitlen >>= 8;
        }
    }
}
