#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct PixelModel3 {
    uint8_t type;
    uint8_t length;
    uint8_t maxpos;
    uint8_t fshift;
    uint16_t size;
    uint32_t cntsum;
    uint8_t symbols[256];
    uint16_t freqs[256];
    uint16_t freqs1[256];
    uint16_t cnts[256];
    uint8_t dectab[32];
} PixelModel3;

PixelModel3 *m;
PixelModel3 n;
int c;
int d;
int e;
int g;
int k;
int q;
int p;

void init_vars() {
    // Allocate and initialize m
    m = (PixelModel3*)calloc(1, sizeof(PixelModel3));
    if (!m) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Set loop parameters
    c = 256;  // Must be <= 256 to avoid out-of-bounds on symbols[256] and freqs[256]
    e = 2;    // Arbitrary shift value, reasonable for scaling

    // Initialize m->symbols and m->freqs with valid data
    for (int i = 0; i < c; i++) {
        m->symbols[i] = (uint8_t)(i & 0xFF);
        m->freqs[i] = (uint16_t)(1 + (i % 100));  // Non-zero frequencies
    }

    // Zero-initialize the rest of m
    m->type = 0;
    m->length = c;
    m->maxpos = c - 1;
    m->fshift = e;
    m->size = c;
    m->cntsum = 0;
    for (int i = 0; i < 256; i++) {
        m->freqs1[i] = 0;
    }
    memset(m->dectab, 0, sizeof(m->dectab));

    // Initialize n's arrays to prevent undefined behavior
    memset(n.symbols, 0, sizeof(n.symbols));
    memset(n.freqs, 0, sizeof(n.freqs));
    memset(n.freqs1, 0, sizeof(n.freqs1));
    memset(n.cnts, 0, sizeof(n.cnts));
    memset(n.dectab, 0, sizeof(n.dectab));

    // Initialize scalar fields of n
    n.type = 0;
    n.length = 0;
    n.maxpos = 0;
    n.fshift = 0;
    n.size = 0;
    n.cntsum = 0;

    // Initialize scalars used in loop
    d = 0;
    g = 0;
    q = 0;
    k = 0;
    p = 0;
}