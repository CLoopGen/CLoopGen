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

    // Set m->size to a value less than or equal to 256 to avoid overflow in loop condition
    // Choose m->size = 128 to ensure safe arithmetic in loop setup
    m->size = 128;

    // Initialize symbols array with valid indices (0-255), using sequential mapping
    for (int i = 0; i < 256; ++i) {
        m->symbols[i] = (uint8_t)i;
    }

    // Initialize other fields to reasonable values (not used in loop but for completeness)
    m->type = 0;
    m->length = 0;
    m->maxpos = 0;
    m->fshift = 0;
    m->cntsum = 0;
    for (int i = 0; i < 256; ++i) {
        m->freqs[i] = 0;
        m->freqs1[i] = 0;
        m->cnts[i] = 0;
    }
    for (int i = 0; i < 32; ++i) {
        m->dectab[i] = 0;
    }

    // Initialize n structure
    n.type = 0;
    n.length = 0;
    n.maxpos = 0;
    n.fshift = 0;
    n.size = 0;
    n.cntsum = 0;
    for (int i = 0; i < 256; ++i) {
        n.freqs[i] = 0;
        n.cnts[i] = 0;
        n.freqs1[i] = 0;
    }
    for (int i = 0; i < 32; ++i) {
        n.dectab[i] = 0;
    }

    // Initialize scalar variables to zero; they will be set in the loop header
    c = 0;
    d = 0;
    e = 0;
    g = 0;
    q = 0;
}