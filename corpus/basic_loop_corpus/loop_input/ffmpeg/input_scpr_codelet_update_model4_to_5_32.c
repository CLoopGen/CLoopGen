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
PixelModel3 n;
int c;
int e;
int g;

void init_vars() {
    // Allocate and initialize m
    m = (PixelModel3*)malloc(sizeof(PixelModel3));
    if (!m) return;

    // Set size to ~64k elements to ensure loop runs about 0.01s
    // assuming moderate CPU speed and optimization level
    m->size = 65536;

    // Ensure symbol and freq arrays are initialized within bounds
    for (int i = 0; i < 256; i++) {
        m->symbols[i] = (uint8_t)(i % 256);
        m->freqs[i] = (uint16_t)((i * 7) % 32768);
        m->freqs1[i] = (uint16_t)((i * 13) % 16384);
        m->cnts[i] = (uint16_t)((i * 3) % 8192);
    }
    for (int i = 256; i < m->size; i++) {
        int idx = i % 256;
        m->symbols[i] = (uint8_t)((i + idx) % 256);
        m->freqs[i] = (uint16_t)((i + idx * 7) % 32768);
    }

    // Initialize other fields of m
    m->type = 1;
    m->length = 255;
    m->maxpos = 255;
    m->fshift = 4;
    m->cntsum = 1000000;

    // Initialize n's fields that are written in the loop
    for (int i = 0; i < 256; i++) {
        n.symbols[i] = 0;
        n.freqs[i] = 0;
    }

    // Initialize scalar variables
    c = 0;
    e = 0;
    g = 0;
}