#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
uint32_t value;
PixelModel3 n;
int c;
int e;

void init_vars() {
    // Allocate and initialize m
    m = (PixelModel3*)malloc(sizeof(PixelModel3));
    if (!m) return;

    // Set deterministic initial values
    m->type = 1;
    m->length = 1;
    m->maxpos = 1;
    m->fshift = 1;
    m->size = 256;  // Maximum safe size given array bounds
    m->cntsum = 0;

    // Initialize symbols and freqs such that loop runs ~256 iterations
    // Spread symbols from 0 to 255, set value to middle so about half are less
    for (int i = 0; i < 256; i++) {
        m->symbols[i] = (uint8_t)(i);
        m->freqs[i] = (uint16_t)(i * 3 + 10);
        m->freqs1[i] = (uint16_t)(i * 2 + 5);
        m->cnts[i] = (uint16_t)(i + 1);
    }
    for (int i = 0; i < 32; i++) {
        m->dectab[i] = (uint8_t)(i * 7);
    }

    // Set value so that approximately half the symbols are less than value
    // This ensures the loop runs around 128 iterations — sufficient for measurable time
    value = 128;

    // Initialize n with safe values (will be overwritten in loop)
    n.type = 0;
    n.length = 0;
    n.maxpos = 0;
    n.fshift = 0;
    n.size = 0;
    n.cntsum = 0;
    for (int i = 0; i < 256; i++) {
        n.symbols[i] = 0;
        n.freqs[i] = 0;
        n.freqs1[i] = 0;
        n.cnts[i] = 0;
    }
    for (int i = 0; i < 32; i++) {
        n.dectab[i] = 0;
    }

    // Initialize loop counters
    c = 0;
    e = 0;
}