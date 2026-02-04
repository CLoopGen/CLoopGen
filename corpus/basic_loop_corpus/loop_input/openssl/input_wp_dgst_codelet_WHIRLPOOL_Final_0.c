#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

WHIRLPOOL_CTX *c;
size_t i;
size_t j;
size_t v;
unsigned char *p;

void init_vars() {
    c = (WHIRLPOOL_CTX *)malloc(sizeof(WHIRLPOOL_CTX));
    if (!c) return;

    for (size_t idx = 0; idx < 4; ++idx) {
        c->bitlen[idx] = (idx + 1) * 1024;
    }

    const size_t data_size = 1024 * 128;
    unsigned char *buffer = (unsigned char *)malloc(data_size);
    if (!buffer) {
        free(c);
        return;
    }

    p = buffer + data_size - 1;

    c->bitoff = 0;
    for (size_t idx = 0; idx < 64; ++idx) {
        c->H.c[idx] = (unsigned char)(idx % 256);
        c->data[idx] = (unsigned char)((idx * 3) % 256);
    }
}