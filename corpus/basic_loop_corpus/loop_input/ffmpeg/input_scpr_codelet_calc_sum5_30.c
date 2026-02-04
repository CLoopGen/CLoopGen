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
uint32_t a;

void init_vars() {
    m = (PixelModel3*)malloc(sizeof(PixelModel3));
    if (!m) exit(1);

    m->type = 1;
    m->length = 2;
    m->maxpos = 3;
    m->fshift = 4;
    m->size = 256; 
    m->cntsum = 0;

    for (int i = 0; i < 256; i++) {
        m->symbols[i] = (uint8_t)(i % 256);
        m->freqs[i] = (uint16_t)(i % 100 + 1);
        m->freqs1[i] = (uint16_t)(i % 50 + 1);
        m->cnts[i] = (uint16_t)(i % 75 + 1);
    }

    for (int i = 0; i < 32; i++) {
        m->dectab[i] = (uint8_t)(i % 16);
    }

    a = 0;
}