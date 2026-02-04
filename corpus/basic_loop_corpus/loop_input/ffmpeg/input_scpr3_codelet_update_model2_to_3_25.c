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
    // Allocate memory for m
    m = (PixelModel3*)calloc(1, sizeof(PixelModel3));
    if (!m) {
        exit(1);
    }

    // Set size to a value that will make the loop run for reasonable time
    // Each iteration is very cheap (a single byte copy), so we need enough iterations
    // to reach ~0.01 seconds. On modern CPUs, ~10-100 million iterations might be needed.
    // We'll set size to 10,000,000 as a good middle ground (~10MB accessed)
    size = 10000000;

    // Ensure that size does not exceed the actual array bounds of symbols
    // But note: in the loop, we access m->symbols[i] and n.symbols[i] for i in [0, size)
    // However, symbols arrays are only 256 bytes long. So we must cap size at 256
    // Otherwise, out-of-bounds access occurs -> undefined behavior / segfault

    // Therefore, to prevent SIGSEGV, we must limit size to 256
    size = 256;

    // Initialize m->symbols with some data
    for (uint32_t i = 0; i < size; i++) {
        m->symbols[i] = (uint8_t)(i * i + 3 * i + 42);
    }

    // Initialize other fields if needed (not used in loop, but safe to zero)
    m->type = 1;
    m->length = 1;
    m->maxpos = 1;
    m->fshift = 1;
    m->size = 1;
    m->cntsum = 1;
    for (int i = 0; i < 256; i++) {
        m->freqs[i] = 1;
        m->freqs1[i] = 1;
        m->cnts[i] = 1;
    }
    for (int i = 0; i < 32; i++) {
        m->dectab[i] = 1;
    }

    // Initialize n's symbols to zero or arbitrary values
    for (int i = 0; i < 256; i++) {
        n.symbols[i] = 0;
    }
    // Other n fields initialization
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