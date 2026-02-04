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

    // Set realistic model size up to 256, but we'll use 200 to stay under loop bound
    m->size = 200;
    
    // Initialize value to a number larger than most symbols, but not too large
    value = 200;

    // Initialize symbols and freqs arrays
    for (int i = 0; i < 256; i++) {
        m->symbols[i] = (uint8_t)(i * 1.2); // increasing sequence
        m->freqs[i] = (uint16_t)(100 + (i % 100));
        m->freqs1[i] = 1;
        m->cnts[i] = 1;
    }

    // Initialize other fields
    m->type = 1;
    m->length = 10;
    m->maxpos = 50;
    m->fshift = 4;
    m->cntsum = 10000;

    // Initialize dectab
    for (int i = 0; i < 32; i++) {
        m->dectab[i] = i % 16;
    }

    // Zero-initialize n
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

    // Initialize scalars
    c = 0;
    e = 0;
}