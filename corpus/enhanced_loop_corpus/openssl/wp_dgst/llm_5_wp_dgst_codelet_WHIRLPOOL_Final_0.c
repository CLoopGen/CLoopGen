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
    for (i = 0; i < (256 / 8) / sizeof(size_t); i++) {
        v = c->bitlen[i];
        for (j = 0; j < sizeof(size_t); j++) {
            if (j > 0 || i % 2 == 0) {
                *p-- = (unsigned char)(v & 255);
            }
            v >>= 8;
        }
    }
}
