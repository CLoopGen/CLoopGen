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
    // Variant 2: Strided memory access — process every other byte, then fill in gaps (interleaved pattern)
    size_t total_iters = (256 / 8) / sizeof(size_t);
    unsigned char stride_buf[32];
    int pos = 0;

    // First pass: strided access by 2 (even indices)
    for (i = 0; i < total_iters; i++) {
        size_t v_local = c->bitlen[i];
        for (j = 0; j < sizeof(size_t); j += 2) { // Stride of 2 in byte extraction
            stride_buf[pos] = (unsigned char)(v_local & 255);
            v_local >>= 8;
            pos++;
            v_local >>= 8; // Skip next byte for striding
        }
    }

    // Second pass: odd-indexed bytes
    for (i = 0; i < total_iters; i++) {
        size_t v_local = c->bitlen[i];
        v_local >>= 8; // Shift once to get to odd byte
        for (j = 1; j < sizeof(size_t) && (j+1) <= sizeof(size_t); j += 2) {
            stride_buf[pos] = (unsigned char)(v_local & 255);
            v_local >>= 8;
            pos++;
            v_local >>= 8;
        }
    }

    // Write all collected bytes in reverse to *p
    for (int k = pos - 1; k >= 0; k--) {
        *p-- = stride_buf[k];
    }
}
