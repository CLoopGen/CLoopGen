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
    m = (PixelModel3*)calloc(1, sizeof(PixelModel3));
    if (!m) exit(1);

    m->type = 1;
    m->length = 256;
    m->maxpos = 255;
    m->fshift = 4;
    m->size = 256;
    m->cntsum = 0;

    for (int i = 0; i < 256; i++) {
        m->symbols[i] = i;
        m->freqs[i] = (i * 7 + 1) % 100;
        m->freqs1[i] = (i * 11 + 3) % 90;
        m->cnts[i] = (i * 5 + 7) % 80;
    }

    for (int i = 0; i < 32; i++) {
        m->dectab[i] = i ^ 0x1F;
    }

    a = 0;
}