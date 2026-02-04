#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
uint16_t cnts[256];
int b;
uint32_t a;

void init_vars() {
    m = (PixelModel3*)malloc(sizeof(PixelModel3));
    if (!m) exit(1);

    m->type = 1;
    m->length = 1;
    m->maxpos = 1;
    m->fshift = 1;
    m->size = 256; 
    m->cntsum = 0;

    for (int i = 0; i < 256; i++) {
        m->symbols[i] = i % 256;
        m->freqs[i] = i * 3;
        m->freqs1[i] = i * 5;
        m->cnts[i] = i * 7;
    }

    for (int i = 0; i < 32; i++) {
        m->dectab[i] = i * 11;
    }

    for (int i = 0; i < 256; i++) {
        cnts[i] = 0;
    }

    b = 0;
    a = 0;
}