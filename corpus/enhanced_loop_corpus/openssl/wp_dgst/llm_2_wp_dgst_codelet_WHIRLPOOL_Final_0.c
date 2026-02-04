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
    // Variant 1: Consecutive memory access with reversed iteration and direct array indexing
    size_t total_bytes = (256 / 8);
    size_t idx = 0;
    unsigned char temp[32]; // Local buffer for consecutive write before copying backward to *p
    int k = 0;

    for (i = 0; i < total_bytes / sizeof(size_t); i++) {
        size_t v_local = c->bitlen[i];
        for (j = 0; j < sizeof(size_t); j++) {
            temp[k++] = (unsigned char)(v_local & 255);
            v_local >>= 8;
        }
    }

    // Write consecutively from temp in reverse order to *p
    for (k = k - 1; k >= 0; k--) {
        *p-- = temp[k];
    }
}
