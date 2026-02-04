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
int _usr_index;

void init_vars() {
    m = (PixelModel3*)malloc(sizeof(PixelModel3));
    if (!m) exit(1);

    m->size = 255;
    _usr_index = 0;

    for (int i = 0; i < 256; i++) {
        m->symbols[i] = (uint8_t)(i & 0xFF);
        m->freqs[i] = (uint16_t)(i % 100);
        m->freqs1[i] = (uint16_t)((i + 10) % 100);
        m->cnts[i] = (uint16_t)((i + 20) % 100);
    }

    m->type = 1;
    m->length = 255;
    m->maxpos = 254;
    m->fshift = 4;
    m->cntsum = 123456789;

    for (int i = 0; i < 32; i++) {
        m->dectab[i] = (uint8_t)((i * 7) % 255);
    }
}