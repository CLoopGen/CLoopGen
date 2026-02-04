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
    size_t unroll_factor = 2;
    size_t iter = (256 / 8) / sizeof(size_t);
    for (i = 0; i < iter; i += unroll_factor) {
        size_t limit = (i + unroll_factor <= iter) ? unroll_factor : 1;
        if (limit == 2) {
            v = c->bitlen[i];
            for (j = 0; j < sizeof(size_t); j++, v >>= 8)
                *p-- = (unsigned char)(v & 255);
            v = c->bitlen[i+1];
            for (j = 0; j < sizeof(size_t); j++, v >>= 8)
                *p-- = (unsigned char)(v & 255);
        } else {
            v = c->bitlen[i];
            for (j = 0; j < sizeof(size_t); j++, v >>= 8)
                *p-- = (unsigned char)(v & 255);
        }
    }
}
