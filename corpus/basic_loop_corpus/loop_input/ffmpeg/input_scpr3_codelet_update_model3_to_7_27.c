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
int d;
int e;
int g;
int q;

void init_vars() {
    // Allocate and initialize m
    m = (PixelModel3*)malloc(sizeof(PixelModel3));
    if (!m) exit(1);

    // Initialize m->size to a value that ensures the loop runs enough iterations
    // to take ~0.01 seconds. The loop runs m->size iterations.
    // On a modern CPU, a simple loop body like this might run ~1e8-1e9 iterations per second.
    // So for 0.01s, we want about 1e6 to 1e7 iterations.
    // Let's choose 2^16 = 65536 which is in that range and safe for our array bounds.
    m->size = 65536 % 256; // Must be <= 256 because it indexes symbols[256] via g < c

    // Constrain size to valid range [0,256] since it controls loop count and array indexing
    if (m->size > 256) m->size = 256;
    if (m->size == 0) m->size = 1;

    // Initialize symbols used in the loop: q = m->symbols[q], where q starts as g
    for (int i = 0; i < m->size; i++) {
        // Map index to a valid symbol in [0,255] to safely index n.freqs[symbol]
        m->symbols[i] = i % 256;
    }

    // Zero-initialize other fields of m to avoid undefined behavior
    m->type = 0;
    m->length = 0;
    m->maxpos = 0;
    m->fshift = 0;
    m->cntsum = 0;
    for (int i = 0; i < 256; i++) {
        m->freqs[i] = 0;
        m->freqs1[i] = 0;
        m->cnts[i] = 0;
    }
    for (int i = 0; i < 32; i++) {
        m->dectab[i] = 0;
    }

    // Initialize n structure
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
        n.symbols[i] = 0;
    }
    for (int i = 0; i < 32; i++) {
        n.dectab[i] = 0;
    }

    // Initialize scalars that are used before assignment in loop
    c = 0;
    d = 0;
    e = 0;
    g = 0;
    q = 0;
}