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
int c;
int d;
int e;

void init_vars() {
    m = (PixelModel3*)aligned_alloc(64, sizeof(PixelModel3));
    
    m->type = 1;
    m->length = 1;
    m->maxpos = 1;
    m->fshift = 1;
    m->size = 128; // Set size to half of freqs array size to ensure bounds safety
    m->cntsum = 0;
    
    for (int i = 0; i < 256; i++) {
        m->symbols[i] = i & 0xFF;
        m->freqs[i] = (i < m->size) ? (i * 3 + 10) : 0;
        m->freqs1[i] = i * 2;
        m->cnts[i] = i;
    }
    
    for (int i = 0; i < 32; i++) {
        m->dectab[i] = i ^ 0x1F;
    }
    
    c = 0;
    d = 0;
    e = 0;
}