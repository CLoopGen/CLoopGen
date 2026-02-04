#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
int i;
int b;

void init_vars() {
    // Allocate and initialize m
    m = (PixelModel3*)malloc(sizeof(PixelModel3));
    if (!m) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize scalar fields of m and n
    m->type = 1;
    m->length = 255;
    m->maxpos = 250;
    m->fshift = 7;
    m->size = 256;
    m->cntsum = 1000;

    n.type = 2;
    n.length = 255;
    n.maxpos = 250;
    n.fshift = 6;
    n.size = 256;
    n.cntsum = 2000;

    // Initialize m->symbols with known pattern to allow verification
    for (int j = 0; j < 256; j++) {
        m->symbols[j] = (uint8_t)(j * 31); // Arbitrary but deterministic
        m->freqs[j] = (uint16_t)(j * 17);
        m->freqs1[j] = (uint16_t)(j * 13);
        m->cnts[j] = (uint16_t)(j * 11);
    }
    
    // Initialize n's arrays to zero initially
    memset(n.symbols, 0, sizeof(n.symbols));
    memset(n.freqs, 0, sizeof(n.freqs));
    memset(n.freqs1, 0, sizeof(n.freqs1));
    memset(n.cnts, 0, sizeof(n.cnts));
    memset(n.dectab, 0, sizeof(n.dectab));

    // Set b to 256 to match the array size of symbols
    b = 256;

    // Reset loop index
    i = 0;
}