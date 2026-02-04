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
uint32_t size;

void init_vars() {
    // Allocate and initialize m
    m = (PixelModel3*)calloc(1, sizeof(PixelModel3));
    if (!m) exit(1);

    // Set size to ensure loop runs for meaningful duration (~0.01 sec)
    // Copying 256 bytes per iteration is small, so we can use a moderate size.
    // However, note: n.symbols[i] = m->symbols[i] with i from 0 to size-1
    // Since symbols arrays are only 256 elements long, size must be <= 256
    size = 256;

    // Initialize m's symbols to avoid undefined behavior
    for (int i = 0; i < 256; i++) {
        m->symbols[i] = (uint8_t)(i * i + 3 * i + 1);
    }

    // Initialize other fields if needed (not accessed in loop, but zero for safety)
    m->type = 1;
    m->length = 2;
    m->maxpos = 3;
    m->fshift = 4;
    m->size = 256;
    m->cntsum = 1000;
    for (int i = 0; i < 256; i++) {
        m->freqs[i] = i;
        m->freqs1[i] = i + 1;
        m->cnts[i] = i;
    }
    for (int i = 0; i < 32; i++) {
        m->dectab[i] = (uint8_t)(i * 2);
    }

    // Initialize n if needed (only writing to symbols in loop)
    // No need to initialize n.symbols before write, but zero others
    n.type = 0;
    n.length = 0;
    n.maxpos = 0;
    n.fshift = 0;
    n.size = 0;
    n.cntsum = 0;
    for (int i = 0; i < 256; i++) {
        n.freqs[i] = 0;
        n.freqs1[i] = 0;
        n.cnts[i] = 0;
    }
    for (int i = 0; i < 32; i++) {
        n.dectab[i] = 0;
    }
}